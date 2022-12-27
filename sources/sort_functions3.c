/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:28:15 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/27 01:07:33 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/**
 * @brief rotate stack a to the right (last becomes first)
 * 
 * @param sd 
 */
void	rra(t_stacks_data *sd)
{
	ft_printf("rra\n");
	if (sd->a != NULL)
		stack_rotate(&sd->a, REVERSE);
	return ;
}

/**
 * @brief rotate stack b to the right (last becomes first)
 * 
 * @param sd 
 */
void	rrb(t_stacks_data *sd)
{
	ft_printf("rrb\n");
	if (sd->b != NULL)
		stack_rotate(&sd->b, REVERSE);
	return ;
}

/**
 * @brief rotate stack a and b to the right (last becomes first)
 * 
 * @param sd 
 */
void	rrr(t_stacks_data *sd)
{
	ft_printf("rrr\n");
	if (sd->a != NULL)
		stack_rotate(&sd->a, REVERSE);
	if (sd->b != NULL)
		stack_rotate(&sd->b, REVERSE);
	return ;
}