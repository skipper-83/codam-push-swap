/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/08 11:28:49 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

typedef struct s_stack{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_stacks{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

void	del_stack(t_stack *head)
{
	t_stack	*work;
	t_stack	*to_delete;

	if (head == NULL)
		return ;
	work = head;
	while (head != work->next)
	{
		to_delete = work;
		work = to_delete->next;
		free (to_delete);
	}
	free(work);
}

t_stack	*init_stack(int length)
{
	t_stack	*ret;
	t_stack	*work;
	t_stack	*new;
	int	 i = 0;

	ret = ft_calloc(1, sizeof(t_stack));
	if (ret == NULL)
		return (NULL);
	work = ret;
	work->nbr = i;
	while (--length)
	{
		new = ft_calloc(1, sizeof(t_stack));
		if (new == NULL)
			return (del_stack(ret), NULL);
		i++;
		work->next = new;
		new->prev = work;
		new->nbr = i;
		work = new;
	}
	work->next = ret;
	ret->prev = work;
	return (ret);
}

int	check_all_numbers(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
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
	int	i;
	int	*res;

	i = 1;
	res = malloc(sizeof(int) * argc - 1);
	if (res == NULL)
	{
		ft_printf("Error\n");
		exit(1);
	}
	while (i < argc)
	{
		if (!check_all_numbers(argv[i]))
		{
			ft_printf("Error not all ints\n");
			exit(1);
		}
		res[i - 1] = ft_atoi(argv[i]); // FIX INT OVERFLOW
		i++;
	}
	return (res);
}

void	stack_del_one(t_stack **head, t_stack *to_del)
{
	if (to_del == *head)
		*head = (*head)->next;
	to_del->prev->next = to_del->next;
	to_del->next->prev = to_del->prev;
	free (to_del);
}

int	stack_add_front(t_stack **head, int val)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->next = *head;
	new->prev = (*head)->prev;
	new->nbr = val;
	(*head)->prev->next = new;
	(*head)->prev = new;
	*head = new;
	return (1);
}

void	stack_swap(t_stack *head)
{
	int	buf;

	if (head == NULL || head->next == head)
		return ;
	buf = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = buf;
}

void	print_stack(t_stack *head)
{
	t_stack	*work;
	int		i;

	work = head;
	i = 0;
	ft_printf("\nLIST DUMP\n");
	while (work->next != head)
	{
		ft_printf("item %i \t -> nbr %i\n", i++, work->nbr);
		ft_printf("\t -> addr %p\n", work);
		ft_printf("\t -> next %p\n", work->next);
		ft_printf("\t -> prev %p\n", work->prev);
		work = work->next;
	}
	ft_printf("item %i \t -> nbr %i\n", i++, work->nbr);
	ft_printf("\t -> addr %p\n", work);
	ft_printf("\t -> next %p\n", work->next);
	ft_printf("\t -> prev %p\n\n", work->prev);
}

int	main(int argc, char **argv)
{
	t_stack	*test_stack;
	int		*numbers;
	int		i;

	if (argc > 1)
		numbers = set_argv_to_int(argv, argc);
	test_stack = init_stack(argc - 1);
	i = 0;

	while (i < argc - 1)
	{
		test_stack->nbr = numbers [i];
		// ft_printf("assigned %i to list item %i\n", test_stack->nbr, i);
		test_stack = test_stack->next;
		i++;
	}
	ft_printf("list now at number %i\n", test_stack->nbr);
	// ft_printf("assigned %i to list item %i\n", test_stack->nbr, i);
	print_stack(test_stack);
	stack_del_one(&test_stack, test_stack->prev);
	print_stack(test_stack);
	stack_add_front(&test_stack, 9);
	print_stack(test_stack);
	stack_swap(test_stack);
	print_stack(test_stack);
	del_stack(test_stack);
	return (0);
}
