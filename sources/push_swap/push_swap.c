/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/09 11:49:41 by avan-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	select_operation(t_sd *sd);

int	main(int argc, char **argv)
{
	t_sd	*sd;

	if (argc < 2)
		return (1);
	sd = initialize_ps(argc, argv);
	if (sd == NULL)
		return (1);
	if (stack_sorted(sd->a))
		return (free(sd->chunks), free_sd(sd), 0);
	if (select_operation(sd) == 1)
		return (free(sd->chunks), free_sd(sd), 0);
	return (free(sd->chunks), free_sd(sd), 0);
}

/**
 * @brief	Select the correct operation (small for 5 and under),
 * 			else (>5) execute push_chuncks to sort the stack into chuncks,
 * 			loop push_three until stack B is empty and stack A is sorted.
 * 			Use sort_three for biggest three items in Stack A
 * 
 * 
 * @param sd 
 * @return int 
 */
static int	select_operation(t_sd *sd)
{
	if (sd->length < 6)
	{
		if (!sort_small(sd))
			return (ft_putstr_fd(MEM_ERR, 2), 1);
	}
	else
	{
		if (!push_chunks(sd))
			return (ft_putstr_fd(MEM_ERR, 2), free_sd(sd), 1);
		if (!stack_sorted(sd->a))
			sort_three(sd);
		sd->sorted_size += 3;
		while (sd->sorted_size < sd->length)
		{
			if (!push_three(sd))
				return (ft_putstr_fd(MEM_ERR, 2), free_sd(sd), 1);
		}
	}
	return (0);
}
