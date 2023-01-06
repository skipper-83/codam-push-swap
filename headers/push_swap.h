/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:17:10 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/06 16:49:28 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../sources/libft/libft.h"

# define REVERSE 1
# define NORMAL 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
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
# define TOP_S 0
# define BOTTOM_S 1
# define TOP_R 2
# define BOTTOM_R 3

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

typedef struct s_bottom_two
{
	int	smallest;
	int	runner_up;
	int	distances[4];
	int	distance;
	int	operation;
}	t_bt;

typedef struct s_stacks_data
{
	t_stack	*a;
	t_stack	*b;
	int		length;
	int		*chunks;
	int		chunk_count;
	int		cur_chunk;
	int		sorted_size;
	int		sorted_bottom;
}	t_sd;

//
// PUSH CHUNK FUNCTIONS

int			push_chunks(t_sd *sd);

//
// INIT FUNCTIONS

t_sd		*initialize(int argc, char **argv);

//
// SHARED INIT FUNCIONS

t_sd		*init_sd(int *nmbrs, int length);
int			*init_numbers_array(int argc, char **argv);

//
// CHECKER FUNCTIONS

int			double_check(int *arr, int length);
int			check_all_nmbrs(char *s);
int			stack_sorted(t_stack *stack);

//
// POSITION FUNCTIONS

t_top_three	*get_positions(t_stack *stack);
int			stack_size(t_stack *stack);

//
// SMALL OPERATION FUNCTIONS

void		sort_three(t_sd *sd);
int			sort_small(t_sd *sd);

//
// SMALL OPERATION UITLS FUNCTIONS

int			execute_small_operation(t_sd *sd, t_bt *bt);
t_bt		*get_small_positions(t_stack *stack);

//
// BIG OPERATION FUNCTIONS

int			execute_operation(t_sd *sd);

//
// OPERATION UTIL FUNCTIONS

void		get_operation(t_top_three *tt, int stack_len);
void		rotate_i(t_sd *sd, void (*r)(t_sd *), int i);

//
// STACK FUNCTIONS

void		stack_del(t_stack *head);
void		stack_del_one(t_stack **head, t_stack *to_del);
int			stack_add_front(t_stack **head, int val);
void		stack_swap(t_stack *head);
void		stack_rotate(t_stack **head, int direction);

//
// PRINT FUNCTIOND

void		print_stacks(t_sd *sd);
void		print_stack(t_stack *head);

//
// SORT FUNCTIONS 1

void		sa(t_sd *sd);
void		sb(t_sd *sd);
void		ss(t_sd *sd);
int			pa(t_sd *sd);
int			pb(t_sd *sd);

//
// SORT FUNCTIONS 2
void		ra(t_sd *sd);
void		rb(t_sd *sd);
void		rr(t_sd *sd);

//
// SORT FUNCTIONS 3
void		rra(t_sd *sd);
void		rrb(t_sd *sd);
void		rrr(t_sd *sd);	

#endif