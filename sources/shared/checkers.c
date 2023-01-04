/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:28:22 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/04 01:05:29 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_all_nmbrs(char *s);

/**
 * @brief	Convert argv to int. Check if input is all numbers, and if  all
 * 			numbers are of INT size.
 * 
 * @param argv 
 * @param argc 
 * @return int* 
 */
int	*argv_to_int(char **argv, int argc)
{
	int		i;
	long	number;
	int		*res;

	i = 1;
	number = 0;
	res = malloc(sizeof(int) * argc - 1);
	if (res == NULL)
		return (ft_putstr_fd(MEM_ERR, 2), free(res), NULL);
	while (i < argc)
	{
		if (!check_all_nmbrs(argv[i]))
			return (ft_putstr_fd(INPUT_ERR, 2), free(res), NULL);
		number = ft_atoli(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (ft_putstr_fd(INPUT_ERR, 2), free(res), NULL);
		res[i - 1] = number;
		i++;
	}
	return (res);
}

static int	check_all_nmbrs(char *s)
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
