/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:18:28 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/04 00:57:05 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	define_chunks(t_sd *sd, int *nmbrs);
static int	*bubble_sort_and_double_check(int *arr, int len);

/**
 * @brief Initialize the stacks:
 * 			- parse argv to integer array
 * 			- put all numbers in stack a
 * 			- sort numbers in int array and check for doubles
 * 			- define chunks based on medians/quarters in sorted int array
 * 			- exit with error when input error encountered
 * 
 * @param argc 
 * @param argv 
 * @return t_stacks_data* 
 */
t_sd	*init_sd(int argc, char **argv)
{
	t_sd	*sd;
	t_stack	*a;
	int		*nmbrs;

	sd = ft_calloc(1, sizeof(t_sd));
	a = NULL;
	if (sd == NULL)
		return (ft_putstr_fd(MEM_ERR, 2), NULL);
	nmbrs = argv_to_int(argv, argc);
	if (nmbrs == NULL)
		return (free(sd), NULL);
	sd->length = argc - 1;
	while (argc > 1)
		stack_add_front(&a, nmbrs[--argc - 1]);
	if (a == NULL)
		return (ft_putstr_fd(MEM_ERR, 2), free(sd), NULL);
	sd->a = a;
	nmbrs = bubble_sort_and_double_check(nmbrs, sd->length);
	if (nmbrs == NULL)
		return (ft_putstr_fd(INPUT_ERR, 2), stack_del(a), free(sd), NULL);
	sd->sorted_bottom = nmbrs[0];
	if (!define_chunks(sd, nmbrs))
		return (ft_putstr_fd(MEM_ERR, 2), \
		stack_del(a), free(sd), free(nmbrs), NULL);
	return (free(nmbrs), sd);
}

/**
 * @brief	define beginnings and endings of chunks the pile of 
 * 			numbers must be split up in. 
 * 			Every chunck (except the last when pile is of odd length) 
 * 			has same size. Amount of chunks is determined 
 * 			by formula sd->length / 86 + 2.34
 * 
 * @param sd 
 * @param nmbrs 
 * @return int 
 */
static int	define_chunks(t_sd *sd, int *nmbrs)
{
	int	start;
	int	end;
	int	i;

	sd->chunk_count = ft_round((float)sd->length / 86 + 2.34);
	sd->chunks = malloc(sizeof(int) * sd->chunk_count * 2);
	if (sd->chunks == NULL)
		return (0);
	i = 0;
	while (i < sd->chunk_count)
	{
		start = (sd->length / sd->chunk_count) * i;
		if (i == sd->chunk_count - 1)
			end = sd->length - 1;
		else
			end = ((sd->length / sd->chunk_count) * (i + 1) - 1);
		sd->chunks[i * 2] = nmbrs[start];
		sd->chunks[(i * 2) + 1] = nmbrs[end];
		i++;
	}
	return (1);
}

static int	*bubble_sort_and_double_check(int *arr, int len)
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
