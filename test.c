/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/08 22:47:22 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
// t_stacks	*init_stacks(int *values, int length)
// {
// 	t_stack	*a;
// 	t_stack *b;	
// }

int	*set_argv_to_int(char **argv, int argc)
{
	int		i;
	long	number;
	int		*res;

	i = 1;
	number = 0;
	res = malloc(sizeof(int) * argc - 1);
	if (res == NULL)
		return (PRINT_ERROR, free(res), exit(1), NULL);
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

// 2147483647
int	main(int argc, char **argv)
{
	t_stack	*test_stack;
	int		*numbers;

	if (argc > 1)
		numbers = set_argv_to_int(argv, argc);
	else
		return (0);
	test_stack = NULL;
	// i = 0;

	while (argc > 1)
	{
		// test_stack->nbr = numbers [i];
		// ft_printf("assigned %i to list item %i\n", test_stack->nbr, i);
		// test_stack = test_stack->next;
		// ft_printf("argc %i\n", --argc);
		stack_add_front(&test_stack, numbers[--argc - 1]);
		// i++;
	}
	ft_printf("list now at number %i\n", test_stack->nbr);
	// ft_printf("assigned %i to list item %i\n", test_stack->nbr, i);
	print_stack(test_stack);
	ft_printf("\nDEL ONE\n");
	stack_del_one(&test_stack, test_stack);
		print_stack(test_stack);
	stack_add_front(&test_stack, 9);
	print_stack(test_stack);
	stack_swap(test_stack);
	print_stack(test_stack);
	stack_swap(test_stack);
	print_stack(test_stack);
	stack_rotate(&test_stack, NORMAL);
	print_stack(test_stack);
	stack_rotate(&test_stack, REVERSE);
	print_stack(test_stack);
	if (test_stack)
		stack_del(test_stack);
	return (0);
}
