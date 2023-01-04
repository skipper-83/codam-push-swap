/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:29:11 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/04 14:29:21 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_sd *sd)
{
	// print_stacks(sd);
	if (sd->a->nbr > sd->a->prev->nbr && sd->a->nbr > sd->a->next->nbr)
	{
		ra(sd);
		if (sd->a->nbr > sd->a->next->nbr)
			sa(sd);
		return ;
	}
	if (sd->a->nbr < sd->a->next->nbr && sd->a->nbr < sd->a->prev->nbr)
		rra(sd);
	if (sd->a->nbr > sd->a->next->nbr && sd->a->nbr < sd->a->prev->nbr)
		sa(sd);
	else
		rra(sd);
}