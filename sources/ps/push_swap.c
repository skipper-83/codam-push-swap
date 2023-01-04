/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/05 00:04:27 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	get_small_operation(t_bt *bt, int stack_len)
// {
// 	if (bt->distances[TOP_S] > bt->distances[BOTTOM_S])
// 	{	
// 		bt->operation = 2;
// 		if (bt->distances[BOTTOM_R] < bt->distances[BOTTOM_S] && stack_len > 1)
// 			bt->operation++;
// 	}
// 	else
// 	{
// 		if (bt->distances[TOP_R] < bt->distances[TOP_S] && stack_len > 1)
// 			bt->operation++;
// 	}
// }

static void	get_small_pos(t_bt *bt, t_stack *stack, int stack_len)
{
	bt->smallest = INT_MAX;
	bt->distance = 0;
	while (bt->distance < stack_len)
	{
		if (stack->nbr <= bt->smallest)
		{
			bt->smallest = stack->nbr;
			bt->distances[TOP_S] = bt->distance;
		}
		stack = stack->next;
		bt->distance++;
	}
	if (bt->distances[TOP_S] == 0)
		bt->distances[BOTTOM_S] = 0;
	else
		bt->distances[BOTTOM_S] = stack_len - bt->distances[TOP_S];
}

static void	get_second_pos(t_bt *bt, t_stack *stack, int stack_len)
{
	bt->runner_up = INT_MAX;
	bt->distance = 0;
	while (bt->distance < stack_len)
	{
		if (stack->nbr <= bt->runner_up && stack->nbr > bt->smallest)
		{
			bt->runner_up = stack->nbr;
			bt->distances[TOP_R] = bt->distance;
		}
		stack = stack->next;
		bt->distance++;
	}
	if (bt->distances[TOP_R] == 0)
		bt->distances[BOTTOM_R] = 0;
	else
		bt->distances[BOTTOM_R] = stack_len - bt->distances[TOP_R];
}

int	get_shortest(t_bt *bt, int len)
{
	int	i;
	int	shortest;
	int	ret;

	i = 0;
	ret = 0;
	shortest = INT_MAX;
	while (i < len)
	{
		if (bt->distances[i] < shortest)
		{
			shortest = bt->distances[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	execute_small_operation(t_sd *sd, t_bt *bt)
{
	// ft_printf("distance: %i\n", bt->distances[bt->operation]);
	if (bt->operation == TOP_S || bt->operation == TOP_R)
	{
		if (bt->distances[bt->operation] > 1)
			ra(sd);
		if (bt->distances[bt->operation] > 0)
			sa(sd);
	}
	else
	{
		while (bt->distances[bt->operation]-- > 0)
			rra(sd);

	}
	if (!pb(sd))
		return (0);
	return (1);
}

t_bt	*get_small_positions(t_stack *stack)
{
	t_bt	*bt;
	int		stack_len;

	bt = ft_calloc(1, sizeof(t_bt));
	if (bt == NULL)
		return (NULL);
	stack_len = stack_size(stack);
	get_small_pos(bt, stack, stack_len);
	get_second_pos(bt, stack, stack_len);
	// ft_printf("smallest: %i, runner-up: %i\n", bt->smallest, bt->runner_up);
	// ft_printf("%i:%i:%i:%i", bt->distances[0], bt->distances[1], bt->distances[2], bt->distances[3]);
	bt->operation = get_shortest(bt, (stack_len - 3)  * 2);
	// if (bt->TOP_S > bt->BOTTOM_S)
	// else
	
	// {	
	// 	bt->operation = 2;
	// 	if (bt->BOTTOM_R < bt->BOTTOM_S && stack_len > 1)
	// 		bt->operation++;
	// }
	// else
	// {
	// 	if (bt->r_top < bt->TOP_S && stack_len > 1)
	// 		bt->operation++;
	// }
	return (bt);
}

int	sort_small(t_sd *sd)
{
	t_bt	*bt;
	int		len;

	len = stack_size(sd->a);
	if (len > 3)
	{
		bt = ft_calloc(1, sizeof(t_bt));
		if (bt == NULL)
			return (ft_putstr_fd(MEM_ERR, 2), 0);
		while (stack_size(sd->a) > 3)
		{
			bt = get_small_positions(sd->a);
			// print_stacks(sd);
			// ft_printf("tt big is %i\n", bt->smallest);
			// ft_printf("operation is %i\n", bt->operation);
			execute_small_operation(sd, bt);
			// print_stacks(sd);
			// get_small_operation(bt, len);
			// ft_printf("other op is: %i", bt->operation);
			// mb_b(sd, tt, &len);
			// print_stacks(sd);
			// break ;
			free(bt);
		}
		if (!stack_sorted(sd->a))
			sort_three(sd);
		if (sd->b->nbr < sd->b->next->nbr)
			sb(sd);
		if (!pa(sd))
			return (0);
		if (!pa(sd))
			return (0);
		// print_stacks(sd);
	}
	else
		sort_three(sd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_sd	*sd;
	int		i;

	if (argc < 2)
		return (1);
	sd = initialize(argc, argv);
	if (sd == NULL)
		return (1);
	if (stack_sorted(sd->a))
		return (stack_del(sd->a), free(sd->chunks), free(sd), 0);
	i = 0;
	if (sd->length < 6)
	{
		sort_small(sd);
		// sort_three(sd);
	}
	else
	{
		if (!push_chunks(sd))
			return (ft_putstr_fd(MEM_ERR, 2), free(sd), 1);
		if (!stack_sorted(sd->a))
			sort_three(sd);
		while (sd->sorted_size < sd->length)
		{
			if (!execute_operation(sd))
				return (ft_putstr_fd(MEM_ERR, 2), free(sd), 1);
		}
	}
	return (stack_del(sd->a), free(sd->chunks), free(sd), 0);
}
