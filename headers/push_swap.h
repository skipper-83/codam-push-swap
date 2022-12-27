/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:17:10 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/27 01:08:07 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../sources/libft/libft.h"

# define REVERSE 1
# define NORMAL 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11
# define PRINT_ERROR ft_printf("Error\n")

typedef struct s_stack{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_stacks_data
{
	t_stack	*a;
	t_stack	*b;
	int		biggest;
	int		smallest;
	int		length;
}	t_stacks_data;

//
// STACK FUNCTIONS

void	stack_del(t_stack *head);
void	stack_del_one(t_stack **head, t_stack *to_del);
int		stack_add_front(t_stack **head, int val);
void	stack_swap(t_stack *head);
void	stack_rotate(t_stack **head, int direction);
	void	print_stack(t_stack *head);

//
// SORT FUNCTIONS 1

void	sa(t_stacks_data *sd);
void	sb(t_stacks_data *sd);
void	ss(t_stacks_data *sd);
void	pa(t_stacks_data *sd);
void	pb(t_stacks_data *sd);

//
// SORT FUNCTIONS 2
void	ra(t_stacks_data *sd);
void	rb(t_stacks_data *sd);
void	rr(t_stacks_data *sd);

//
// SORT FUNCTIONS 3
void	rra(t_stacks_data *sd);
void	rrb(t_stacks_data *sd);
void	rrr(t_stacks_data *sd);	

#endif