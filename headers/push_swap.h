/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:17:10 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/03 01:50:56 by albertvanan      ###   ########.fr       */
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
# define SMALLEST_TOP 0
# define SMALLEST_BOTTOM 1
# define BIGGEST_TOP 2
# define BIGGEST_BOTTOM 3
# define BIGGEST 4
# define SMALLEST 5
# define DISTANCE 6
# define MEM_ERR "Error\n"
# define INPUT_ERR "Error\n"
# define TOP_B 0
# define TOP_MB 1
# define TOP_MSB 2
# define TOP_SMB 3
# define BOTTOM_B 4
# define BOTTOM_MB 5
# define BOTTOM_MSB 6
# define BOTTOM_SMB 7

typedef struct s_stack{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_top_three
{
	int	big;
	int	middle;
	int	small;
	int	b_top;
	int	b_bottom;
	int	m_top;
	int	m_bottom;
	int	s_top;
	int	s_bottom;
	int	distance;
	int	operation;
}	t_top_three;


typedef struct s_stacks_data
{
	t_stack	*a;
	t_stack	*b;
	int		length;
	int		*chunks;
	int		chunk_count;
	int		cur_chunk;
	int		small_on_top;
	// int		small_on_bottom;
	int		big_on_top;
	int		sorted_top;
	int		sorted_size;
	int		sorted_bottom;
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
int		pa(t_stacks_data *sd);
int		pb(t_stacks_data *sd);

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