/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:22:19 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/07 10:39:44 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_sd	*init_checker(int argc, char **argv);
static t_op	get_operation(char *input);
static int	read_command(t_sd *sd);

int	main(int argc, char **argv)
{
	t_sd	*sd;

	if (argc < 2)
		return (1);
	sd = init_checker(argc, argv);
	if (sd == NULL)
		return (1);
	if (!read_command(sd))
		return (free_stacks(sd), 1);
	if (stack_sorted(sd->a) && sd->b == NULL)
		ft_printf(OK);
	else
		ft_printf(KO);
	return (free_stacks(sd), 0);
}

/**
 * @brief	Initialize. Declare and fill numbers array 
 * 			and stack A, return null on error. Input
 * 			chec isdone in init_numbers_array()
 * 
 * @param argc 
 * @param argv 
 * @return t_sd* 
 */
static t_sd	*init_checker(int argc, char **argv)
{
	t_sd	*sd;
	int		*nmbrs;
	int		length;

	nmbrs = init_numbers_array(argc, argv);
	if (nmbrs == NULL)
		return (NULL);
	length = argc - 1;
	sd = init_sd(nmbrs, length);
	if (sd == NULL)
		return (free(nmbrs), NULL);
	return (free(nmbrs), sd);
}

/**
 * @brief	Return proper operation function based on input. Return
 * 			NULL is input is invalid.
 * 
 * @param input 
 * @return t_op 
 */
static t_op	get_operation(char *input)
{
	if (!ft_strncmp(input, SA, ft_strlen(input)))
		return (sa);
	if (!ft_strncmp(input, SB, ft_strlen(input)))
		return (sb);
	if (!ft_strncmp(input, SS, ft_strlen(input)))
		return (ss);
	if (!ft_strncmp(input, PA, ft_strlen(input)))
		return (pa);
	if (!ft_strncmp(input, PB, ft_strlen(input)))
		return (pb);
	if (!ft_strncmp(input, RA, ft_strlen(input)))
		return (ra);
	if (!ft_strncmp(input, RB, ft_strlen(input)))
		return (rb);
	if (!ft_strncmp(input, RR, ft_strlen(input)))
		return (rr);
	if (!ft_strncmp(input, RRA, ft_strlen(input)))
		return (rra);
	if (!ft_strncmp(input, RRB, ft_strlen(input)))
		return (rrb);
	if (!ft_strncmp(input, RRR, ft_strlen(input)))
		return (rrr);
	return (NULL);
}

/**
 * @brief	Read and execute operations from std input.
 * 
 * @param sd 
 * @return int 
 */
static int	read_command(t_sd *sd)
{
	t_op	operation;
	char	*command;

	command = get_next_line(0);
	while (command != NULL)
	{
		operation = get_operation(command);
		free (command);
		if (operation == NULL)
			return (ft_putstr_fd(INPUT_ERR, 2), 0);
		operation(sd);
		command = get_next_line(0);
	}
	return (1);
}

