/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:37:05 by avan-and          #+#    #+#             */
/*   Updated: 2022/11/02 11:26:04 by avan-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief find t_find in str in first n charachters
 * 
 * @param str 
 * @param to_find 
 * @param n 
 * @return char* 
 */
char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;

	if (!*to_find)
		return ((char *)str);
	while (n && *str && (n >= ft_strlen(to_find)))
	{
		if (*str == *to_find)
		{
			i = 0;
			while (*(str + i) == to_find[i] && to_find[i])
				i++;
			if (!to_find[i])
				return ((char *)str);
		}
		str++;
		n--;
	}
	return (NULL);
}
