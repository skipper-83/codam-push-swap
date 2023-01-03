/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/03 22:12:33 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_stacks(t_stacks_data *sd)
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

int	*bubble_sort_and_double_check(int *arr, int len)
{
	int	i;
	int	sorted;
	int	swap;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] == arr[i + 1])
				return (NULL);
			if (arr[i] > arr[i + 1])
			{
				sorted = 0;
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
			}
			i++;
		}
	}
	return (arr);
}

int	check_all_nmbrs(char *s)
{
	int	i;
	int	max_length;

	i = 0;
	max_length = 9;
	while (s[i])
	{
		if (i == 0 && (s[i] == '+' || s[i] == '-'))
		{
			max_length = 10;
			i++;
		}
		if (!ft_isdigit(s[i]))
			return (0);
		if (i > max_length)
			return (0);
		i++;
	}
	return (1);
}

// void	(*g_stack_function[])(t_stacks_data *sd) = 
// {NULL, sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

int	*argv_to_int(char **argv, int argc)
{
	int		i;
	long	number;
	int		*res;

	i = 1;
	number = 0;
	res = malloc(sizeof(int) * argc - 1);
	if (res == NULL)
		return (ft_printf(MEM_ERR), free(res), NULL);
	while (i < argc)
	{
		if (!check_all_nmbrs(argv[i]))
			return (ft_printf(INPUT_ERR), free(res), NULL);
		number = ft_atoli(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (ft_printf(INPUT_ERR), free(res), NULL);
		res[i - 1] = number;
		i++;
	}
	return (res);
}

int	define_chunks(t_stacks_data *sd, int *nmbrs)
{
	int	start;
	int	end;
	int	i;

	sd->chunk_count = ft_round((float)sd->length / 86 + 2.34);
	// ft_printf("chunk count: %f\n", (float)sd->length / 86 + 2.34);
	// sd->chunk_count = 8;
	sd->chunks = malloc(sizeof(int) * sd->chunk_count * 2);
	if (sd->chunks == NULL)
		return (0);
	i = 0;
	while (i < sd->chunk_count)
	{
		start = (sd->length / sd->chunk_count) * i;
		if (i == sd->chunk_count - 1)
			end = sd->length - 1;
		else
			end = ((sd->length / sd->chunk_count) * (i + 1) - 1);
		sd->chunks[i * 2] = nmbrs[start];
		sd->chunks[(i * 2) + 1] = nmbrs[end];
		// ft_printf("%i: start %i end %i: %i -> %i -- %i:%i\n", i, start, end, nmbrs[start], nmbrs[end], sd->chunks[i * 2], sd->chunks[i * 2 + 1]);
		i++;
	}
	return (1);
}

t_stacks_data	*init_sd(int argc, char **argv)
{
	t_stacks_data	*sd;
	t_stack			*a;
	int				*nmbrs;

	sd = ft_calloc(1, sizeof(t_stacks_data));
	a = NULL;
	if (sd == NULL)
		return (ft_printf(MEM_ERR), NULL);
	nmbrs = argv_to_int(argv, argc);
	if (nmbrs == NULL)
		return (ft_printf(MEM_ERR), free(sd), NULL);
	sd->length = argc - 1;
	while (argc > 1)
		stack_add_front(&a, nmbrs[--argc - 1]);
	if (a == NULL)
		return (ft_printf(MEM_ERR), free(sd), NULL);
	sd->a = a;
	nmbrs = bubble_sort_and_double_check(nmbrs, sd->length);
	if (nmbrs == NULL)
		return (ft_printf(INPUT_ERR), stack_del(a), free(sd), NULL);
	sd->sorted_bottom = nmbrs[0];
	if (!define_chunks(sd, nmbrs))
		return (ft_printf(MEM_ERR), stack_del(a), free(sd), free(nmbrs), NULL);
	return (free(nmbrs), sd);
}

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

int	*get_distances(t_stack *stack, int stack_len)
{
	int		*ret;

	ret = ft_calloc(7, sizeof(int));
	if (ret == NULL)
		return (NULL);
	ret[SMALLEST] = stack->nbr;
	ret[BIGGEST] = stack->nbr;
	while (ret[DISTANCE] < stack_len)
	{
		if (stack->nbr > ret[BIGGEST])
		{
			ret[BIGGEST] = stack->nbr;
			ret[BIGGEST_TOP] = ret[DISTANCE];
		}
		if (stack->nbr < ret[SMALLEST])
		{
			ret[SMALLEST] = stack->nbr;
			ret[SMALLEST_TOP] = ret[DISTANCE];
		}
		stack = stack->next;
		ret[DISTANCE]++;
	}
	ret[BIGGEST_BOTTOM] = stack_len - ret[BIGGEST_TOP];
	ret[SMALLEST_BOTTOM] = stack_len - ret[SMALLEST_TOP];
	return (ret);
}

void	get_big_pos(t_top_three *tt, t_stack *stack, int stack_len)
{
	tt->big = INT_MIN;
	tt->distance = 0;
	// ft_printf("Getting big, stack len %i\n", stack_len);
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

void	get_middle_pos(t_top_three *tt, t_stack *stack, int stack_len)
{
	tt->middle = INT_MIN;
	tt->distance = 0;
	// ft_printf("Getting middle, stack len %i\n", stack_len);
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

void	get_small_pos(t_top_three *tt, t_stack *stack, int stack_len)
{
	tt->small = INT_MIN;
	tt->distance = 0;
	// ft_printf("Getting small, stack len %i\n", stack_len);
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

void	get_operation(t_top_three *tt, int stack_len)
{
	if (tt->b_top > tt->b_bottom)
	{	
		tt->operation = 4;
		if (tt->m_bottom < tt->b_bottom && stack_len > 1)
		{
			tt->operation++;
			if (tt->s_bottom < tt->b_bottom && stack_len > 2)
				tt->operation++;
			if (tt->s_bottom < tt->m_bottom && stack_len > 2)
				tt->operation++;
		}
	}
	else
	{
		if (tt->m_top < tt->b_top && stack_len > 1)
		{
			tt->operation++;
			if (tt->s_top < tt->b_top && stack_len > 2)
				tt->operation++;
			if (tt->s_top < tt->m_top && stack_len > 2)
				tt->operation++;
		}
	}
}

t_top_three *get_positions(t_stack *stack)
{
	t_top_three	*tt;
	int			stack_len;
	// char		*operations[] = {"big_top", "middle_top", "middle_small_top", "small_middle_top", "big_bottom", "middle_bottom", "middle_small_bottom", "small_middle_bottom"};

	tt = ft_calloc(1, sizeof(t_top_three));
	if (tt == NULL)
		return (NULL);
	stack_len = stack_size(stack);
	get_big_pos(tt, stack, stack_len);
	get_middle_pos(tt, stack, stack_len);
	get_small_pos(tt, stack, stack_len);
	get_operation(tt, stack_len);
	// ft_printf("%3i : %3i : %3i @@ %3i:%-3i -- %3i:%-3i -- %3i:%-3i --> %s\n", tt->big, tt->middle, tt->small, tt->b_top, tt->b_bottom, tt->m_top, tt->m_bottom, tt->s_top, tt->s_bottom, operations[tt->operation]);
	return (tt);
}

void	rotate_i(t_stacks_data *sd, void (*rotation)(t_stacks_data *), int i)
{
	while (i > 0)
	{
		rotation(sd);
		i--;
	}
}

int	execute_operation(t_stacks_data *sd, t_top_three *tt)
{
	void	(*rotate)(t_stacks_data *);
	int		correction;

	if (tt->operation < 4)
	{
		rotate = rb;
		correction = 1;
		tt->big = tt->b_top;
		tt->middle = tt->m_top;
		tt->small = tt->s_top;
	}
	else
	{
		rotate = rrb;
		correction = 0;
		tt->big = tt->b_bottom;
		tt->middle = tt->m_bottom;
		tt->small = tt->s_bottom;
	}
	if (tt->operation == TOP_SMB || tt->operation == BOTTOM_SMB)
	{
		rotate_i(sd, rotate, tt->small);
		if (!pa(sd))
			return (0);
		if (tt->middle - tt->small - 1 * correction > 1 && tt->operation < 4)
		{
			rr(sd);
			rotate_i(sd, rotate, tt->middle - tt->small - 1 - 1 * correction);
		}
		else
		{
			ra(sd);
			rotate_i(sd, rotate, tt->middle - tt->small - 1 * correction);
		}
		if (!pa(sd))
			return (0);
		rotate_i(sd, rotate, tt->big - tt->middle - 1 * correction);
		if (!pa(sd))
			return (0);
		sa(sd);
		rra(sd);
		sd->sorted_size += 3;
	}
	else if (tt->operation == TOP_MSB || tt->operation == BOTTOM_MSB)
	{
		// ft_printf("Executing MSB: %i\n", tt->operation);
		rotate_i(sd, rotate, tt->middle);
		if (!pa(sd))
			return (0);
		rotate_i(sd, rotate, tt->small - tt->middle - 1 * correction);
		if (!pa(sd))
			return (0);
		if (tt->big - tt->small - 1 * correction > 1 && tt->operation < 4)
		{
			rr(sd);
			rotate_i(sd, rotate, tt->big - tt->small - 1 - 1 * correction);
		}
		else
		{
			ra(sd);
			rotate_i(sd, rotate, tt->big - tt->small - 1 * correction);
		}
		if (!pa(sd))
			return (0);
		sa(sd);
		rra(sd);
		sd->sorted_size += 3;
	}
	else if (tt->operation == TOP_MB || tt->operation == BOTTOM_MB)
	{
		rotate_i(sd, rotate, tt->middle);
		if (!pa(sd))
			return (0);
		rotate_i(sd, rotate, tt->big - tt->middle - 1 * correction);
		if (!pa(sd))
			return (0);
		sa(sd);
		sd->sorted_size += 2;
	}
	else if (tt->operation == TOP_B || tt->operation == BOTTOM_B)
	{
		rotate_i(sd, rotate, tt->big);
		if (!pa(sd))
			return (0);
		sd->sorted_size++;
	}
	return (1);
}

int	select_shortest_route(int *distances)
{
	int	i;
	int	shortest;
	int	ret;

	i = 1;
	shortest = distances[0];
	ret = 0;
	while (i < 4)
	{
		if (distances[i] < shortest)
		{
			shortest = distances[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

void	push_max_three(t_stacks_data *sd)
{
	t_top_three	*tt;

	tt = get_positions(sd->b);
	// print_stacks(sd);
	execute_operation(sd, tt);
}

void	execute_rotations(t_stacks_data *sd, int *distances, int operation)
{
	int	i;

	i = 0;
	while (i < distances[operation])
	{
		if (operation == BIGGEST_BOTTOM || operation == SMALLEST_BOTTOM)
			rrb(sd);
		if (operation == BIGGEST_TOP || operation == SMALLEST_TOP)
		{
			if (sd->small_on_top)
			{
				rr(sd);
				sd->small_on_top = 0;
			}
			else
				rb (sd);
		}
		i++;
	}
	if (sd->small_on_top)
	{
		ra(sd);
		sd->small_on_top = 0;
	}
}

int	push_next_candidate(t_stacks_data *sd)
{
	int	*distances;
	// t_top_three *positions;
	int	stack_len;
	int	operation;

	stack_len = stack_size(sd->b);
	// print_stacks(sd);
	distances = get_distances(sd->b, stack_len);
	// positions = get_positions(sd->b);
	if (distances == NULL)
		return (0);
	operation = select_shortest_route(distances);
	execute_rotations(sd, distances, operation);
	if (!pa(sd))
		return (0);
	sd->sorted_size++;
	if (operation == SMALLEST_TOP || operation == SMALLEST_BOTTOM)
	{
		sd->small_on_top = 1;
		// sd->small_on_bottom++;
	}
	if (operation == BIGGEST_TOP || operation == BIGGEST_BOTTOM)
		sd->big_on_top++;
	// print_stacks(sd);
	free(distances);
	return (1);
}

int	sort_chunk(t_stacks_data *sd)
{
	int	i;
	int	size_b;

	i = 0;
	size_b = stack_size(sd->b);
	while (i < size_b)
	{
		if (!push_next_candidate(sd))
			return (0);
		i++;
	}
	if (sd->small_on_top)
	{
		ra(sd);
		sd->small_on_top = 0;
	}
	// print_stacks(sd);
	// ft_printf("big on top: %i; amount done %i, length: %i\n", sd->big_on_top, sd->amount_done, sd->length);
	i = 0;
	// if (sd->amount_done < sd->length / 2)
	// {
	// printf()
	// ft_printf("resetting stack\n");
	// if (sd->cur_chunk >= sd->chunk_count / 2)
	// // if (sd->cur_chunk > sd->chunk_count / 2)
	// {
		while (i++ < (size_b - sd->big_on_top))
			rra(sd);
	// }
	// else
	// {
	// 	while (i++ < (sd->big_on_top + sd->sorted_size - size_b))
	// 		ra(sd);
	// }
	// }
	// else
	// {
		// while (i++ < (sd->length - (sd->amount_done - sd->big_on_top)))
			// rra(sd);
	// }
	sd->big_on_top = 0;
	sd->small_on_top = 0;
	return (1);
}

int	push_chunks(t_stacks_data *sd)
{
	int		i;
	int		j;
	int		pushed;
	int		half;

	i = 0;
	while (i < sd->chunk_count * 2)
	{
		half = sd->chunks[i] + (sd->chunks[i + 1] - sd->chunks[i]) / 2;
		j = 0;
		pushed = 0;
		while (sd->a && j < sd->length)
		{
			// if (sd->b && sd->b->nbr > half && sd->b->nbr > sd->b->next->nbr)
			// 	rb(sd);
			if (sd->a->nbr >= sd->chunks[i] && sd->a->nbr <= sd->chunks[i + 1])
			{
				// if (sd->b && sd->b->nbr > half && sd->b->nbr > sd->b->next->nbr)
				// 	rb(sd);
				if (sd->b && sd->b->nbr > half && sd->b->nbr > sd->b->next->nbr)
					rb(sd);
				if (!pb(sd))
					return (0);
				pushed++;
				if (pushed == sd->length / sd->chunk_count && (i / 2 + 1) < sd->chunk_count)
					break ;
			}
			else
			{
				if (sd->b && sd->b->nbr > half && sd->b->nbr > sd->b->next->nbr)
					rr(sd);
				else
					ra(sd);
			}
			j++;
		}
		if (sd->b->nbr > half)
			rb(sd);
		i += 2;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	t_stacks_data	*sd;
	int				i;

	if (argc < 2)
		return (1);
	sd = init_sd(argc, argv);
	if (sd == NULL)
		return (1);
	// ft_printf("\nchunks %i\n", ft_round((float)(argc - 1) / 55 + 2));
	// print_stacks(sd);
	i = 0;
	push_chunks(sd);
	while (sd->sorted_size < sd->length)
	{
		push_max_three(sd);
	}
	// sort_chunk(sd);
	// while (i < sd->chunk_count * 2)
	// {
	// 	sd->cur_chunk++;
	// 	// ft_printf("chunk: %i -> %i\n", sd->cur_chunk, (sd->cur_chunk - 1) * 2);
	// 	// ft_printf("pushing\n");
	// 	// push_chunks(sd);
	// 	// print_stacks(sd);
	// 	// ft_printf("sorting\n");
	// 	// sort_chunk(sd);
	// 	// print_stacks(sd);
	// 	// ft_printf("Current chunk: %i of %i\n", sd->cur_chunk, sd->chunk_count);
	// 	i += 2;
	// }

	// i = 0;
	// while (i < stack_size(sd->b))
	// 	push_next_candidate(sd);
	// if (sd->small_on_top)
	// {
	// 	ra(sd);
	// 	sd->small_on_top = 0;
	// }
	// print_stacks(sd);
	// ft_printf("big on top: %i; amount done %i\n", sd->big_on_top, sd->amount_done);
	// i = 0;
	// while (i++ < sd->big_on_top)
	// 	ra(sd);
	// sd->small_on_top = 0;
	// print_stacks(sd);
	
	return (0);
}
