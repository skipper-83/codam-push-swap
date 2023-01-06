/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:36:52 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 22:54:17 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

/**
 * @brief Print stacks a and b. For debugging only
 * 
 * @param sd 
 */
void	print_stacks(t_sd *sd)
{
	t_stack	*work_a;
	t_stack	*work_b;

	work_a = sd->a;
	work_b = sd->b;
	ft_printf("\nstacks:\n--------\n");
	while (!(work_a == NULL && work_b == NULL))
	{
		if (work_a)
			ft_printf("%4i", work_a->nbr);
		else
			ft_printf("%4c", ' ');
		if (work_b)
			ft_printf("%4i", work_b->nbr);
		ft_printf("\n");
		if (work_a == NULL || work_a->next == sd->a)
			work_a = NULL;
		else
			work_a = work_a->next;
		if (work_b == NULL || work_b->next == sd->b)
			work_b = NULL;
		else
			work_b = work_b->next;
	}
	ft_printf("--------\n%4c%4c\n\n", 'a', 'b');
}

/**
 * @brief 	Print a single stack with its adresses. 
 * 			For debugging only.
 * 
 * @param head 
 */
void	print_stack(t_stack *head)
{
	t_stack	*work;
	int		i;

	ft_printf("\nLIST DUMP\n");
	if (head == NULL)
		return ;
	work = head;
	i = 0;
	while (work->next != head)
	{
		ft_printf("item %i \t -> nbr %i\n", i++, work->nbr);
		ft_printf("\t -> addr %p\n", work);
		ft_printf("\t -> next %p\n", work->next);
		ft_printf("\t -> prev %p\n", work->prev);
		work = work->next;
	}
	ft_printf("item %i \t -> nbr %i\n", i++, work->nbr);
	ft_printf("\t -> addr %p\n", work);
	ft_printf("\t -> next %p\n", work->next);
	ft_printf("\t -> prev %p\n\n", work->prev);
}
