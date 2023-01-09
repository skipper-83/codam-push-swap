/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:59:49 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/09 11:46:20 by avan-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	smb(t_sd *sd, t_top_three *tt, int (*r)(t_sd *), int correction);
static int	msb(t_sd *sd, t_top_three *tt, int (*r)(t_sd *), int correction);
static int	mb_b(t_sd *sd, t_top_three *tt, int (*r)(t_sd *), int correction);
static void	init(int (**rotate)(t_sd *), t_top_three *tt, int *correction);

/**
 * @brief Execute the operation found in get_operation
 * 
 * @param sd 
 * @param tt 
 * @return int 
 */
int	push_three(t_sd *sd)
{	
	int			(*rotate)(t_sd *);
	t_top_three	*tt;
	int			correction;
	int			ret;

	tt = get_positions(sd->b);
	if (tt == NULL)
		return (0);
	ret = 0;
	correction = 0;
	rotate = NULL;
	init (&rotate, tt, &correction);
	if (tt->operation == TOP_SMB || tt->operation == BOTTOM_SMB)
		ret = smb(sd, tt, rotate, correction);
	else if (tt->operation == TOP_MSB || tt->operation == BOTTOM_MSB)
		ret = msb(sd, tt, rotate, correction);
	else
		ret = mb_b(sd, tt, rotate, correction);
	return (free(tt), ret);
}

/**
 * @brief	Init values. Rotate function pointer passed as pointer 
 * 			for extra funkiness.
 * 
 * @param rotate 
 * @param tt 
 * @param correction 
 */
static void	init(int (**rotate)(t_sd *), t_top_three *tt, int *correction)
{
	if (tt->operation < 4)
	{
		*rotate = rb;
		*correction = 1;
		tt->big = tt->b_top;
		tt->middle = tt->m_top;
		tt->small = tt->s_top;
	}
	else
	{
		*rotate = rrb;
		*correction = 0;
		tt->big = tt->b_bottom;
		tt->middle = tt->m_bottom;
		tt->small = tt->s_bottom;
	}
}

/**
 * @brief	Execute SMB. Optimization in rotations of stack a and b if applicable
 * 			(hence rr or ra). Return 0 if allocation for pa fails.
 * 
 * @param sd 
 * @param tt 
 * @param r 
 * @param correction 
 * @return int 
 */
static int	smb(t_sd *sd, t_top_three *tt, int (*r)(t_sd *), int correction)
{
	rotate_i(sd, r, tt->small);
	if (!pa(sd))
		return (0);
	if (tt->middle - tt->small - 1 * correction > 1 && tt->operation < 4)
	{
		rr(sd);
		rotate_i(sd, r, tt->middle - tt->small - 1 - 1 * correction);
	}
	else
	{
		ra(sd);
		rotate_i(sd, r, tt->middle - tt->small - 1 * correction);
	}
	if (!pa(sd))
		return (0);
	rotate_i(sd, r, tt->big - tt->middle - 1 * correction);
	if (!pa(sd))
		return (0);
	sa(sd);
	rra(sd);
	sd->sorted_size += 3;
	return (1);
}

/**
 * @brief	Execute MSB. Optimization in rotations of stack a and b if applicable
 * 			(hence rr or ra). Return 0 if allocation for pa fails.
 * 
 * @param sd 
 * @param tt 
 * @param r 
 * @param correction 
 * @return int 
 */
static int	msb(t_sd *sd, t_top_three *tt, int (*r)(t_sd *), int correction)
{
	rotate_i(sd, r, tt->middle);
	if (!pa(sd))
		return (0);
	rotate_i(sd, r, tt->small - tt->middle - 1 * correction);
	if (!pa(sd))
		return (0);
	if (tt->big - tt->small - 1 * correction > 1 && tt->operation < 4)
	{
		rr(sd);
		rotate_i(sd, r, tt->big - tt->small - 1 - 1 * correction);
	}
	else
	{
		ra(sd);
		rotate_i(sd, r, tt->big - tt->small - 1 * correction);
	}
	if (!pa(sd))
		return (0);
	sa(sd);
	rra(sd);
	sd->sorted_size += 3;
	return (1);
}

/**
 * @brief	Execute MB or B. Return 0 if allocation for pa fails.
 * 
 * @param sd 
 * @param tt 
 * @param r 
 * @param correction 
 * @return int 
 */
static int	mb_b(t_sd *sd, t_top_three *tt, int (*r)(t_sd *), int correction)
{
	if (tt->operation == TOP_MB || tt->operation == BOTTOM_MB)
	{
		rotate_i(sd, r, tt->middle);
		if (!pa(sd))
			return (0);
		rotate_i(sd, r, tt->big - tt->middle - 1 * correction);
		if (!pa(sd))
			return (0);
		sa(sd);
		sd->sorted_size += 2;
	}
	else if (tt->operation == TOP_B || tt->operation == BOTTOM_B)
	{
		rotate_i(sd, r, tt->big);
		if (!pa(sd))
			return (0);
		sd->sorted_size++;
	}
	return (1);
}
