/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:51:30 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/09 10:56:14 by avan-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "../sources/libft/libft.h"

# define REVERSE 1
# define NORMAL 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define MEM_ERR "Error\n"
# define INPUT_ERR "Error\n"

typedef struct s_stack{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

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
	int		print_command;
	int		verbose;
}	t_sd;

//
// SHARED INIT FUNCIONS

t_sd		*init_sd(int *nmbrs, int length);
int			*init_numbers_array(int argc, char **argv);

//
// STACK FUNCTIONS

void		stack_del(t_stack *head);
void		stack_del_one(t_stack **head, t_stack *to_del);
int			stack_add_front(t_stack **head, int val);
void		stack_swap(t_stack *head);
void		stack_rotate(t_stack **head, int direction);

//
// CHECKER FUNCTIONS

int			double_check(int *arr, int length);
int			check_all_nmbrs(char *s);
int			stack_sorted(t_stack *stack);

//
// PRINT FUNCTIONS

void		free_sd(t_sd *sd);
void		print_stacks(t_sd *sd);
void		print_stack(t_stack *head);

//
// SORT FUNCTIONS 1

int			sa(t_sd *sd);
int			sb(t_sd *sd);
int			ss(t_sd *sd);
int			pa(t_sd *sd);
int			pb(t_sd *sd);

//
// SORT FUNCTIONS 2

int			ra(t_sd *sd);
int			rb(t_sd *sd);
int			rr(t_sd *sd);

//
// SORT FUNCTIONS 3

int			rra(t_sd *sd);
int			rrb(t_sd *sd);
int			rrr(t_sd *sd);	

#endif



