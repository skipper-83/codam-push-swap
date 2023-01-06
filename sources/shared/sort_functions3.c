/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:28:15 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 22:54:29 by albertvanan      ###   ########.fr       */
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
	return (1);
}
