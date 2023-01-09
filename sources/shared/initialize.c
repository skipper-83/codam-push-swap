/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:34:25 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/09 11:24:23 by avan-and         ###   ########.fr       */
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
	if (!ft_strncmp(argv[1], "-v", 2))
		length--;
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
	int		offset;

	i = 1;
	offset = 0;
	if (!ft_strncmp(argv[1], "-v", 2))
		offset = 1;
	number = 0;
	res = malloc(sizeof(int) * argc - (1 + offset));
	if (res == NULL)
		return (ft_putstr_fd(MEM_ERR, 2), free(res), NULL);
	while (i + offset < argc)
	{
		if (!check_all_nmbrs(argv[i + offset]))
			return (ft_putstr_fd(INPUT_ERR, 2), free(res), NULL);
		number = ft_atoli(argv[i + offset]);
		if (number > INT_MAX || number < INT_MIN)
			return (ft_putstr_fd(INPUT_ERR, 2), free(res), NULL);
		res[i - 1] = number;
		i++;
	}
	return (res);
}
