/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:16:54 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 22:54:33 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * @brief	delete full stack
 * 
 * @param head 
 */
void	stack_del(t_stack *head)
{
	t_stack	*work;
	t_stack	*to_delete;

	if (head == NULL)
		return ;
	work = head;
	while (head != work->next)
	{
		to_delete = work;
		work = to_delete->next;
		free (to_delete);
	}
	free(work);
}

/**
 * @brief	delete [to_del] from stack [head]
 * 			if [to_del] is [head], change head to
 * 			next item
 * 			if [to_del] is the only item, set [head]
 * 			to NULL
 * 
 * @param head 
 * @param to_del 
 */
void	stack_del_one(t_stack **head, t_stack *to_del)
{
	if (to_del == *head)
	{
		if (to_del->next == *head)
		{
			free(to_del);
			*head = NULL;
			return ;
		}
		*head = (*head)->next;
	}
	to_del->prev->next = to_del->next;
	to_del->next->prev = to_del->prev;
	free (to_del);
}

/**
 * @brief 	add item to stack [head]
 * 			if [head] is NULL, point prev and next to head
 * 			return 0 on malloc fail
 * 
 * @param head 
 * @param val 
 * @return int 
 */
int	stack_add_front(t_stack **head, int val)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (new == NULL)
		return (0);
	if (*head != NULL)
	{
		new->next = *head;
		new->prev = (*head)->prev;
		(*head)->prev->next = new;
		(*head)->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	new->nbr = val;
	*head = new;
	return (1);
}

/**
 * @brief	swap first two items of stack [head]
 * 
 * @param head 
 */
void	stack_swap(t_stack *head)
{
	int	buf;

	if (head == NULL || head->next == head)
		return ;
	buf = head->nbr;
	head->nbr = head->next->nbr;
	head->next->nbr = buf;
}

/**
 * @brief	rotate stack [head]:
 * 			if direction is NORMAL, rotate CCW, first element becomes last 
 * 			(second element becomes first)
 * 			if direction is REVERSE, rotate CW, last element becomes the first
 * 
 * @param head 
 * @param direction 
 */
void	stack_rotate(t_stack **head, int direction)
{
	if (direction == REVERSE)
		*head = (*head)->prev;
	else if (direction == NORMAL)
		*head = (*head)->next;
}
