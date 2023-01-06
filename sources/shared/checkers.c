/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:28:22 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 22:56:57 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * @brief Check if a number is in the array twice
 * 
 * @param arr 
 * @param length 
 * @return int 
 */
int	double_check(int *arr, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < length)
		{
			if (arr[j] == arr[i] && i != j)
				return (ft_putstr_fd(INPUT_ERR, 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Check if all entries are numbers
 * 
 * @param s 
 * @return int 
 */
int	check_all_nmbrs(char *s)
{
	int	i;
	int	max_length;

	i = 0;
	max_length = 9;
	if (!*s)
		return (0);
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

int	stack_sorted(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	while (stack->next != head)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
