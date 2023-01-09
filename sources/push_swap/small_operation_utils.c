/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_operation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:46:13 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 22:30:45 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_shortest(t_bt *bt, int len);
static void	get_small_pos(t_bt *bt, t_stack *stack, int stack_len);
static void	get_second_pos(t_bt *bt, t_stack *stack, int stack_len);

/**
 * @brief 	Execute operations based on the position of the numbers to 
 * 			be pushed. Options are:
 * 			- Smallest from top
 * 			- Runner uo from top
 * 			- Smallest from bottom
 * 			- Runner up from bottom
 * 
 * @param sd 
 * @param bt 
 * @return int 
 */
int	execute_small_operation(t_sd *sd, t_bt *bt)
{
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
	bt->operation = get_shortest(bt, (stack_len - 3) * 2);
	return (bt);
}

/**
 * @brief	Get the position of the smallest number in a stack
 * 
 * @param bt 
 * @param stack 
 * @param stack_len 
 */
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

/**
 * @brief Get the position of the second smallest number in a stack
 * 
 * @param bt 
 * @param stack 
 * @param stack_len 
 */
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

/**
 * @brief 	Get the shortest objectGet the shoretest route to the
 * 			smallest or second smallest number in stack (whichever is closest to
 * 			the top/bottom)
 * 
 * @param bt 
 * @param len 
 * @return int 
 */
static int	get_shortest(t_bt *bt, int len)
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
