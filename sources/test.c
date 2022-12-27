/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/27 01:07:40 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_stacks(t_stacks_data *sd)
{
	t_stack	*work_a;
	t_stack	*work_b;

	if (sd->a == NULL && sd->b == NULL)
		return ;
	work_a = sd->a;
	work_b = sd->b;
	ft_printf("\nstacks:\n");
	ft_printf("--------\n");
	while (1)
	{
		if (work_a)
			ft_printf("%4i", work_a->nbr);
		else
			ft_printf("%4c", ' ');
		if (work_b)
			ft_printf("%4i", work_b->nbr);
		ft_printf("\n");
		if (work_a == NULL || work_a->next == sd->a)
			work_a = NULL;
		else
			work_a = work_a->next;
		if (work_b == NULL || work_b->next == sd->b)
			work_b = NULL;
		else
			work_b = work_b->next;
		if (work_a == NULL && work_b == NULL)
			break ;
	}
	ft_printf("--------\n");
	ft_printf("%4c%4c\n\n", 'a', 'b');
}



int	check_all_numbers(char *s)
{
	int	i;
	int	max_length;

	i = 0;
	max_length = 9;
	while (s[i])
	{
		if (i == 0 && (s[i] == '+' || s[i] == '-'))
		{
			max_length = 10;
			i++;
		}
		if (!ft_isdigit(s[i]))
			return (0);
		if (i > max_length)
			return (0);
		i++;
	}
	return (1);
}

void	(*g_stack_function[])(t_stacks_data *sd) = {NULL, sa, sb, ss, \
pa, pb, ra, rb, rr, rra, rrb, rrr};

int	*set_argv_to_int(char **argv, int argc)
{
	int		i;
	long	number;
	int		*res;

	i = 1;
	number = 0;
	res = malloc(sizeof(int) * argc - 1);
	if (res == NULL)
		return (ft_printf("Error\n"), free(res), exit(1), NULL);
	while (i < argc)
	{
		if (!check_all_numbers(argv[i]))
			return (PRINT_ERROR, free(res), exit(1), NULL);
		number = ft_atoli(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (PRINT_ERROR, free(res), exit(1), NULL);
		res[i - 1] = number;
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	t_stacks_data	*sd;
	t_stack			*stack_a;
	// t_stack			*stack_b;
	int				*numbers;

	sd = ft_calloc(1, sizeof(t_stacks_data));
	// stack_b = ft_calloc(1, sizeof(t_stack));
	if (argc > 1)
		numbers = set_argv_to_int(argv, argc);
	else
		return (0);
	stack_a = NULL;
	while (argc > 1)
		stack_add_front(&stack_a, numbers[--argc - 1]);
	sd->a = stack_a;
	// sd->b = stack_b;
	// ft_printf("list now at number %i\n", stack_a->nbr);

	// print_stack(sd->a);
	// ft_printf("addy: %p\n", sd->b->next);
	print_stacks(sd);
	g_stack_function[RB](sd);
	g_stack_function[PB](sd);
	g_stack_function[PB](sd);
	g_stack_function[PB](sd);
	print_stacks(sd);
	g_stack_function[RR](sd);
	print_stacks(sd);
	g_stack_function[RA](sd);
	print_stacks(sd);
	g_stack_function[RB](sd);
	print_stacks(sd);
	g_stack_function[RRR](sd);
	print_stacks(sd);
	g_stack_function[RRA](sd);
	print_stacks(sd);
	g_stack_function[RRB](sd);
	print_stacks(sd);
	g_stack_function[SA](sd);
	print_stacks(sd);
	g_stack_function[SB](sd);
	print_stacks(sd);
	g_stack_function[SS](sd);
	print_stacks(sd);

	// ft_printf("\nDEL ONE\n");
	// stack_del_one(&stack_a, stack_a);
	// 	print_stack(stack_a);

	// stack_add_front(&stack_a, 9);
	// print_stack(stack_a);
	// stack_swap(stack_a);
	// print_stack(stack_a);
	// stack_swap(stack_a);
	// print_stack(stack_a);
	// stack_rotate(&stack_a, NORMAL);
	// print_stack(stack_a);
	// stack_rotate(&stack_a, REVERSE);
	// print_stack(stack_a);
	// if (stack_a)
	// 	stack_del(stack_a);
	return (0);
}
