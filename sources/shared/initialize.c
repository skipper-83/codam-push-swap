/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:34:25 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 23:04:37 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

static int	*argv_to_int(char **argv, int argc);

/**
 * @brief Initialize the array with all numbers passes as arguments.
 * 
 * @param argc 
 * @param argv 
 * @return int* 
 */
int	*init_numbers_array(int argc, char **argv)
{
	int	*nmbrs;
	int	length;

	length = argc - 1;
	nmbrs = argv_to_int(argv, argc);
	if (nmbrs == NULL)
		return (NULL);
	if (!double_check(nmbrs, length))
		return (free(nmbrs), NULL);
	return (nmbrs);
}

/**
 * @brief	Put all numbers in stack A, return stacks data.
 * 
 * @param argc 
 * @param argv 
 * @return t_stacks_data* 
 */
t_sd	*init_sd(int *nmbrs, int length)
{
	t_sd	*sd;
	t_stack	*a;

	sd = ft_calloc(1, sizeof(t_sd));
	a = NULL;
	if (sd == NULL)
		return (ft_putstr_fd(MEM_ERR, 2), NULL);
	sd->length = length;
	while (length > 0)
		stack_add_front(&a, nmbrs[--length]);
	if (a == NULL)
		return (ft_putstr_fd(MEM_ERR, 2), free(sd), NULL);
	sd->a = a;
	return (sd);
}

/**
 * @brief	Convert argv to int. Check if input is all numbers, and if  all
 * 			numbers are of INT size.
 * 
 * @param argv 
 * @param argc 
 * @return int* 
 */
static int	*argv_to_int(char **argv, int argc)
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
