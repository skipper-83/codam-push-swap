/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albertvanandel <albertvanandel@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:53:52 by albertvanan       #+#    #+#             */
/*   Updated: 2023/01/04 11:01:14 by albertvanan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_sd	*sd;
	int		i;

	if (argc < 2)
		return (1);
	sd = initialize(argc, argv);
	if (sd == NULL)
		return (1);
	i = 0;
	if (!push_chunks(sd))
		return (ft_putstr_fd(MEM_ERR, 2), free(sd), 1);
	while (sd->sorted_size < sd->length)
	{
		if (!execute_operation(sd))
			return (ft_putstr_fd(MEM_ERR, 2), free(sd), 1);
	}
	return (stack_del(sd->a), free(sd->chunks), free(sd), 0);
}
