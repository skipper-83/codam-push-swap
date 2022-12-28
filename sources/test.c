/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/28 10:25:36 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_stacks(t_stacks_data *sd)
{
	t_stack	*work_a;
	t_stack	*work_b;

	work_a = sd->a;
	work_b = sd->b;
	ft_printf("\nstacks:\n--------\n");
	while (!(work_a == NULL && work_b == NULL))
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
	}
	ft_printf("--------\n%4c%4c\n\n", 'a', 'b');
}

int	*bubble_sort_and_double_check(int *arr, int len)
{
	int	i;
	int	sorted;
	int	swap;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] == arr[i + 1])
				return (NULL);
			if (arr[i] > arr[i + 1])
			{
				sorted = 0;
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
			}
			i++;
		}
	}
	return (arr);
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

int	*argv_to_int(char **argv, int argc)
{
	int		i;
	long	number;
	int		*res;

	i = 1;
	number = 0;
	res = malloc(sizeof(int) * argc - 1);
	if (res == NULL)
		return (ft_printf(MEM_ERR), free(res), NULL);
	while (i < argc)
	{
		if (!check_all_numbers(argv[i]))
			return (ft_printf(INPUT_ERR), free(res), NULL);
		number = ft_atoli(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (ft_printf(INPUT_ERR), free(res), NULL);
		res[i - 1] = number;
		i++;
	}
	return (res);
}
void	define_chunks(int len, int *numbers)
{
	int	chunks;
	int	start;
	int	end;
	int	i;

	chunks = ft_round((float)len / 55 + 2);
	i = 0;
	while (i < chunks)
	{
		start = (len / chunks) * i;
		if (i == chunks - 1)
			end = len - 1;
		else
			end = ((len / chunks) * (i + 1) - 1);
		ft_printf("%i: start %i end %i: %i -> %i\n", i, start, end, numbers[start], numbers[end]);
		i++;
	}
}

t_stacks_data	*init_sd(int argc, char **argv)
{
	t_stacks_data	*sd;
	t_stack			*a;
	int				*numbers;

	sd = ft_calloc(1, sizeof(t_stacks_data));
	a = NULL;
	if (sd == NULL)
		return (ft_printf(MEM_ERR), NULL);
	numbers = argv_to_int(argv, argc);
	if (numbers == NULL)
		return (free(sd), NULL);
	sd->length = argc - 1;
	while (argc > 1)
		stack_add_front(&a, numbers[--argc - 1]);
	numbers = bubble_sort_and_double_check(numbers, sd->length);
	if (numbers == NULL)
		return (ft_printf(INPUT_ERR), stack_del(a), free(sd), NULL);
	if (sd->length > 5)
		define_chunks(sd->length, numbers);
	sd->a = a;
	return (sd);
}


int	main(int argc, char **argv)
{
	t_stacks_data	*sd;

	if (argc < 2)
		return (ft_printf(INPUT_ERR), 1);
	sd = init_sd(argc, argv);
	if (sd == NULL)
		return (1);
	ft_printf("\nchunks %i\n", ft_round((float)(argc - 1) / 55 + 2));
	// define_chunks(argc - 1);
	// stack_b = ft_calloc(1, sizeof(t_stack));
	// sd->b = stack_b;
	// ft_printf("list now at number %i\n", stack_a->nbr);

	// print_stack(sd->a);
	// ft_printf("addy: %p\n", sd->b->next);
	// print_stacks(sd);
	// g_stack_function[RB](sd);
	// g_stack_function[PB](sd);
	// g_stack_function[PB](sd);
	// g_stack_function[PB](sd);
	// print_stacks(sd);
	// g_stack_function[RR](sd);
	// print_stacks(sd);
	// g_stack_function[RA](sd);
	// print_stacks(sd);
	// g_stack_function[RB](sd);
	// print_stacks(sd);
	// g_stack_function[RRR](sd);
	// print_stacks(sd);
	// g_stack_function[RRA](sd);
	// print_stacks(sd);
	// g_stack_function[RRB](sd);
	// print_stacks(sd);
	// g_stack_function[SA](sd);
	// print_stacks(sd);
	// g_stack_function[SB](sd);
	// print_stacks(sd);
	// g_stack_function[SS](sd);
	
	// print_stacks(sd);

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
