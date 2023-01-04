/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_operation_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:44:49 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/04 14:05:37 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief	Determine the operation to be applied based on the
 * 			position of the biggest three objects.
 * 			First: find the fastest route to the biggest object.
 * 			If on the way the second and possibly the third biggest
 * 			numbers are encountered, change operation accordingly.
 * 			Possble operations (from top/bottom, numbers big/middle/small):
 * 			- t_b
 * 			- t_mb
 * 			- t_smb
 * 			- t_msb
 * 			- b_b
 * 			- b_mb
 * 			- b_smb
 * 			- b_msb
 * 			There operationes are indexed and defined in the header file.
 * 
 * @param tt 
 * @param stack_len 
 */
void	get_operation(t_top_three *tt, int stack_len)
{
	if (tt->b_top > tt->b_bottom)
	{	
		tt->operation = 4;
		if (tt->m_bottom < tt->b_bottom && stack_len > 1)
		{
			tt->operation++;
			if (tt->s_bottom < tt->b_bottom && stack_len > 2)
				tt->operation++;
			if (tt->s_bottom < tt->m_bottom && stack_len > 2)
				tt->operation++;
		}
	}
	else
	{
		if (tt->m_top < tt->b_top && stack_len > 1)
		{
			tt->operation++;
			if (tt->s_top < tt->b_top && stack_len > 2)
				tt->operation++;
			if (tt->s_top < tt->m_top && stack_len > 2)
				tt->operation++;
		}
	}
}

/**
 * @brief	Rotate stack for i times given the rotation function passed
 * 			as a pointer.
 * 
 * @param sd 
 * @param rotation 
 * @param i 
 */
void	rotate_i(t_sd *sd, void (*r)(t_sd *), int i)
{
	while (i > 0)
	{
		r(sd);
		i--;
	}
}
