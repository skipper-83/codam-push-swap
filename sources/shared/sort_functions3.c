/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:28:15 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/09 11:22:17 by avan-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * @brief rotate stack a to the right (last becomes first)
 * 
 * @param sd 
 */
int	rra(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("rra\n");
	if (sd->a != NULL)
		stack_rotate(&sd->a, REVERSE);
	if (sd->verbose)
		print_stacks(sd);
	return (1);
}

/**
 * @brief rotate stack b to the right (last becomes first)
 * 
 * @param sd 
 */
int	rrb(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("rrb\n");
	if (sd->b != NULL)
		stack_rotate(&sd->b, REVERSE);
	if (sd->verbose)
		print_stacks(sd);
	return (1);
}

/**
 * @brief rotate stack a and b to the right (last becomes first)
 * 
 * @param sd 
 */
int	rrr(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("rrr\n");
	if (sd->a != NULL)
		stack_rotate(&sd->a, REVERSE);
	if (sd->b != NULL)
		stack_rotate(&sd->b, REVERSE);
	if (sd->verbose)
		print_stacks(sd);
	return (1);
}
