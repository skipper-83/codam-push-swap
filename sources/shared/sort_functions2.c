/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:25:21 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/09 11:22:00 by avan-and         ###   ########.fr       */
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
	if (sd->verbose)
		print_stacks(sd);
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
	if (sd->verbose)
		print_stacks(sd);
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
	if (sd->verbose)
		print_stacks(sd);
	return (1);
}
