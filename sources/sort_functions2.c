/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:25:21 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/27 01:07:29 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/**
 * @brief rotate stack a left (first becomes last)
 * 
 * @param sd 
 */
void	ra(t_stacks_data *sd)
{
	ft_printf("ra\n");
	if (sd->a != NULL)
		stack_rotate(&sd->a, NORMAL);
	return ;
}

/**
 * @brief rotate stack b left (first becomes last)
 * 
 * @param sd 
 */
void	rb(t_stacks_data *sd)
{
	ft_printf("rb\n");
	if (sd->b != NULL)
		stack_rotate(&sd->b, NORMAL);
	return ;
}

/**
 * @brief rotate stack a and b left (first becomes last)
 * 
 * @param sd 
 */
void	rr(t_stacks_data *sd)
{
	ft_printf("rr\n");
	if (sd->a != NULL)
		stack_rotate(&sd->a, NORMAL);
	if (sd->b != NULL)
		stack_rotate(&sd->b, NORMAL);
	return ;
}
