/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:17:10 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/09 11:01:56 by avan-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "shared.h"

# define SMALLEST_TOP 0
# define SMALLEST_BOTTOM 1
# define BIGGEST_TOP 2
# define BIGGEST_BOTTOM 3
# define BIGGEST 4
# define SMALLEST 5
# define DISTANCE 6
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

//
// PUSH CHUNK FUNCTIONS

int			push_chunks(t_sd *sd);

//
// INIT FUNCTIONS

t_sd		*initialize_ps(int argc, char **argv);

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

int			push_three(t_sd *sd);

//
// OPERATION UTIL FUNCTIONS

void		get_operation(t_top_three *tt, int stack_len);
void		rotate_i(t_sd *sd, int (*r)(t_sd *), int i);

#endif