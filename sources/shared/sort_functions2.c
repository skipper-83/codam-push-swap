/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:25:21 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 22:54:25 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * @brief rotate stack a left (first becomes last)
 * 
 * @param sd 
 */
int	ra(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("ra\n");
	if (sd->a != NULL)
		stack_rotate(&sd->a, NORMAL);
	return (1);
}

/**
 * @brief rotate stack b left (first becomes last)
 * 
 * @param sd 
 */
int	rb(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("rb\n");
	if (sd->b != NULL)
		stack_rotate(&sd->b, NORMAL);
	return (1);
}

/**
 * @brief rotate stack a and b left (first becomes last)
 * 
 * @param sd 
 */
int	rr(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("rr\n");
	if (sd->a != NULL)
		stack_rotate(&sd->a, NORMAL);
	if (sd->b != NULL)
		stack_rotate(&sd->b, NORMAL);
	return (1);
}
