/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:32:00 by albertvanan       #+#    #+#             */
/*   Updated: 2022/12/28 10:26:23 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	check_doubles(int *arr, int len, int val)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	val;
	int	current;
	int	*random_numbers;

	if (argc <= 1)
		return (0);
	i = 0;
	val = ft_atoi(argv[1]);
	random_numbers = ft_calloc(val, sizeof(int));
	if (random_numbers == NULL)
		return (0);
	while (i < val)
	{
		current = rand() % (val * 2) - (val / 2);
		if (!check_doubles(random_numbers, i, current))
		{
			random_numbers[i++] = current;
			ft_printf("%i ", current);
		}
	}
}
