/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:29:11 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 16:49:11 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_sd *sd)
{
	if (sd->a->nbr > sd->a->prev->nbr && sd->a->nbr > sd->a->next->nbr)
	{
		ra(sd);
		if (sd->a->nbr > sd->a->next->nbr)
		{
			if (sd->b && sd->b->nbr < sd->b->next->nbr)
				ss(sd);
			else
				sa(sd);
		}
		return ;
	}
	if (sd->a->nbr < sd->a->next->nbr && sd->a->nbr < sd->a->prev->nbr)
		rra(sd);
	if (sd->a->nbr > sd->a->next->nbr && sd->a->nbr < sd->a->prev->nbr)
	{
		if (sd->b && sd->b->nbr < sd->b->next->nbr)
			ss(sd);
		else
			sa(sd);
	}
	else
		rra(sd);
}

int	sort_small(t_sd *sd)
{
	t_bt	*bt;
	int		len;

	len = stack_size(sd->a);
	if (len > 3)
	{
		while (stack_size(sd->a) > 3)
		{
			bt = get_small_positions(sd->a);
			if (bt == NULL)
				return (0);
			if (!execute_small_operation(sd, bt))
				return (free(bt), 0);
			free(bt);
		}
		if (!stack_sorted(sd->a))
			sort_three(sd);
		if (sd->b->nbr < sd->b->next->nbr)
			sb(sd);
		if (!pa(sd) || !pa(sd))
			return (free(bt), 0);
		return (1);
	}
	sort_three(sd);
	return (1);
}
