/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 00:20:58 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/30 14:42:09 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/**
 * @brief swap stack a (sd->a)
 * 
 * @param sd 
 */
void	sa(t_stacks_data *sd)
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
void	sb(t_stacks_data *sd)
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
void	ss(t_stacks_data *sd)
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
int	pa(t_stacks_data *sd)
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
int	pb(t_stacks_data *sd)
{
	ft_printf("pb\n");
	if (sd->a == NULL)
		return (1);
	if (!stack_add_front(&sd->b, sd->a->nbr))
		return (0);
	stack_del_one(&sd->a, sd->a);
	return (1);
}
