/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:20:58 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/09 11:26:01 by avan-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * @brief swap stack a (sd->a)
 * 
 * @param sd 
 */
int	sa(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("sa\n");
	if (sd->a != NULL)
		stack_swap(sd->a);
	if (sd->verbose)
		print_stacks(sd);
	return (1);
}

/**
 * @brief swap stack b (sd->b)
 * 
 * @param sd 
 */
int	sb(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("sb\n");
	if (sd->b != NULL)
		stack_swap(sd->b);
	if (sd->verbose)
		print_stacks(sd);
	return (1);
}

/**
 * @brief swap a and b
 * 
 * @param sd 
 */
int	ss(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("ss\n");
	if (sd->a != NULL)
		stack_swap(sd->a);
	if (sd->b != NULL)
		stack_swap(sd->b);
	if (sd->verbose)
		print_stacks(sd);
	return (1);
}

/**
 * @brief push from b to a
 * 
 * @param sd 
 */
int	pa(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("pa\n");
	if (sd->b == NULL)
		return (1);
	if (!stack_add_front(&sd->a, sd->b->nbr))
		return (0);
	stack_del_one(&sd->b, sd->b);
	if (sd->verbose)
		print_stacks(sd);
	return (1);
}

/**
 * @brief pus from a to b
 * 
 * @param sd 
 */
int	pb(t_sd *sd)
{
	if (sd->print_command)
		ft_printf("pb\n");
	if (sd->a == NULL)
		return (1);
	if (!stack_add_front(&sd->b, sd->a->nbr))
		return (0);
	stack_del_one(&sd->a, sd->a);
	if (sd->verbose)
		print_stacks(sd);
	return (1);
}
