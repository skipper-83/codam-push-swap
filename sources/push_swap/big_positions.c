/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:38:35 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/04 22:40:22 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_small_pos(t_top_three *tt, t_stack *stack, int stack_len);
static void	get_big_pos(t_top_three *tt, t_stack *stack, int stack_len);
static void	get_middle_pos(t_top_three *tt, t_stack *stack, int stack_len);

/**
 * @brief	Get the positions of the biggest, second biggest and third biggest
 * 			number in given stack. Deterime which operation should be applied
 * 			on the basis of this position.
 * 
 * @param stack 
 * @return t_top_three* 
 */
t_top_three	*get_positions(t_stack *stack)
{
	t_top_three	*tt;
	int			stack_len;

	tt = ft_calloc(1, sizeof(t_top_three));
	if (tt == NULL)
		return (NULL);
	stack_len = stack_size(stack);
	get_big_pos(tt, stack, stack_len);
	get_middle_pos(tt, stack, stack_len);
	get_small_pos(tt, stack, stack_len);
	get_operation(tt, stack_len);
	return (tt);
}

/**
 * @brief Return size of given stack.
 * 
 * @param stack 
 * @return int 
 */
int	stack_size(t_stack *stack)
{
	t_stack	*top;
	int		ret;

	if (stack == NULL)
		return (0);
	ret = 1;
	top = stack;
	while (stack->next != top)
	{
		ret++;
		stack = stack->next;
	}
	return (ret);
}

/**
 * @brief	Find biggest number in stack and save distance from top and
 * 			bottom of stack from that number.
 * 
 * @param tt 
 * @param stack 
 * @param stack_len 
 */
static void	get_big_pos(t_top_three *tt, t_stack *stack, int stack_len)
{
	tt->big = INT_MIN;
	tt->distance = 0;
	while (tt->distance < stack_len)
	{
		if (stack->nbr >= tt->big)
		{
			tt->big = stack->nbr;
			tt->b_top = tt->distance;
		}
		stack = stack->next;
		tt->distance++;
	}
	if (tt->b_top == 0)
		tt->b_bottom = 0;
	else
		tt->b_bottom = stack_len - tt->b_top;
}

/**
 * @brief	Find second biggest number in stack and save distance from top and
 * 			bottom of stack from that number.
 * 
 * @param tt 
 * @param stack 
 * @param stack_len 
 */
static void	get_middle_pos(t_top_three *tt, t_stack *stack, int stack_len)
{
	tt->middle = INT_MIN;
	tt->distance = 0;
	if (stack_len < 2)
	{
		tt->middle = tt->big;
		return ;
	}
	while (tt->distance < stack_len)
	{
		if (stack->nbr < tt->big && stack->nbr >= tt->middle)
		{
			tt->middle = stack->nbr;
			tt->m_top = tt->distance;
		}
		stack = stack->next;
		tt->distance++;
	}
	if (tt->m_top == 0)
		tt->m_bottom = 0;
	else
		tt->m_bottom = stack_len - tt->m_top;
}

/**
 * @brief	Find third number in stack and save distance from top and
 * 			bottom of stack from that number.
 * 
 * @param tt 
 * @param stack 
 * @param stack_len 
 */
static void	get_small_pos(t_top_three *tt, t_stack *stack, int stack_len)
{
	tt->small = INT_MIN;
	tt->distance = 0;
	if (stack_len < 3)
	{
		tt->small = tt->big;
		return ;
	}
	while (tt->distance < stack_len)
	{
		if (stack->nbr < tt->middle && stack->nbr >= tt->small)
		{
			tt->small = stack->nbr;
			tt->s_top = tt->distance;
		}
		stack = stack->next;
		tt->distance++;
	}
	if (tt->s_top == 0)
		tt->s_bottom = 0;
	else
		tt->s_bottom = stack_len - tt->s_top;
}
