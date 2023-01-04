/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:20:58 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/03 23:56:10 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief swap stack a (sd->a)
 * 
 * @param sd 
 */
void	sa(t_sd *sd)
{
	ft_printf("sa\n");
	if (sd->a != NULL)
		stack_swap(sd->a);
	return ;
}

/**
 * @brief swap stack b (sd->b)
 * 
 * @param sd 
 */
void	sb(t_sd *sd)
{
	ft_printf("sb\n");
	if (sd->b != NULL)
		stack_swap(sd->b);
	return ;
}

/**
 * @brief swap a and b
 * 
 * @param sd 
 */
void	ss(t_sd *sd)
{
	ft_printf("ss\n");
	if (sd->a != NULL)
		stack_swap(sd->a);
	if (sd->b != NULL)
		stack_swap(sd->b);
	return ;
}

/**
 * @brief push from b to a
 * 
 * @param sd 
 */
int	pa(t_sd *sd)
{
	ft_printf("pa\n");
	if (sd->b == NULL)
		return (1);
	if (!stack_add_front(&sd->a, sd->b->nbr))
		return (0);
	stack_del_one(&sd->b, sd->b);
	return (1);
}

/**
 * @brief pus from a to b
 * 
 * @param sd 
 */
int	pb(t_sd *sd)
{
	ft_printf("pb\n");
	if (sd->a == NULL)
		return (1);
	if (!stack_add_front(&sd->b, sd->a->nbr))
		return (0);
	stack_del_one(&sd->a, sd->a);
	return (1);
}
