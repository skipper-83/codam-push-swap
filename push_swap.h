/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:17:10 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/08 22:46:03 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define REVERSE 1
# define NORMAL 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define PRINT_ERROR ft_printf("Error\n")

typedef struct s_stack{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// STACK FUNCTIONS

void	stack_del(t_stack *head);
void	stack_del_one(t_stack **head, t_stack *to_del);
int		stack_add_front(t_stack **head, int val);
void	stack_swap(t_stack *head);
void	stack_rotate(t_stack **head, int direction);

	void	print_stack(t_stack *head);

#endif