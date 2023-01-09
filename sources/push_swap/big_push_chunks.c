/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_push_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:41:37 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/04 14:39:51 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_push(t_sd *sd, int i, int half, int *pushed);

/**
 * @brief Push consecutive chunks to stack b
 * 
 * @param sd 
 * @return int 
 */
int	push_chunks(t_sd *sd)
{
	int		i;
	int		j;
	int		pushed;
	int		ret;
	int		half;

	i = 0;
	while (i < sd->chunk_count * 2)
	{
		half = sd->chunks[i] + (sd->chunks[i + 1] - sd->chunks[i]) / 2;
		j = 0;
		pushed = 0;
		while (stack_size(sd->a) > 3)
		{
			ret = do_push(sd, i, half, &pushed);
			if (ret == 0)
				return (0);
			if (ret == 2)
				break ;
		}
		if (sd->b->nbr > half)
			rb(sd);
		i += 2;
	}
	return (1);
}

/**
 * @brief	Called inside loop. Return 2 to break loop when chunck size is reached,
 * 			except for last chucnck (which might be longer if the total length is odd).
 *			Rotate stack b if number is in the bigger half of the chunk. Optimize 
 * 			rotations with rr/ra.
 * 
 * @param sd 
 * @param i 
 * @param half 
 * @param pushed 
 * @return int 
 */
static int	do_push(t_sd *sd, int i, int half, int *pushed)
{
	if (sd->a->nbr >= sd->chunks[i] && sd->a->nbr <= sd->chunks[i + 1])
	{
		if (sd->b && sd->b->nbr > half && sd->b->nbr > sd->b->next->nbr)
			rb(sd);
		if (!pb(sd))
			return (0);
		(*pushed)++;
		if (*pushed == sd->length / sd->chunk_count \
			&& (i / 2 + 1) < sd->chunk_count)
			return (2);
	}
	else
	{
		if (sd->b && sd->b->nbr > half && sd->b->nbr > sd->b->next->nbr)
			rr(sd);
		else
			ra(sd);
	}
	return (1);
}
