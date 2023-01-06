/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 22:35:49 by albertvanan      ###   ########.fr       */
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
		return (stack_del(sd->a), free(sd->chunks), free(sd), 0);
	if (select_operation(sd) == 1)
		return (stack_del(sd->a), free(sd->chunks), free(sd), 0);
	return (stack_del(sd->a), free(sd->chunks), free(sd), 0);
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
			return (ft_putstr_fd(MEM_ERR, 2), free(sd), 1);
		if (!stack_sorted(sd->a))
			sort_three(sd);
		while (sd->sorted_size < sd->length)
		{
			if (!push_three(sd))
				return (ft_putstr_fd(MEM_ERR, 2), free(sd), 1);
		}
	}
	return (0);
}
