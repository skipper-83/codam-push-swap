/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-and <avan-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:58:35 by albertvanan       #+#    #+#             */
/*   Updated: 2022/11/18 11:49:39 by avan-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(signed long long n, int ret);
static void	fill_numbers(int len, int sign, long double n, char *ret);
static void	fill_float(int prec, char *ret, int len, long double after_point);

char	*ft_ftoa(long double n, int precision)
{
	char		*ret;
	int			len;
	int			sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = digits((signed long long)n, 0) + sign;
	if (precision > 0)
		len += precision + 1;
	ret = (char *)ft_calloc(sizeof(char), len + 1);
	if (!ret)
		return (NULL);
	fill_numbers(len - precision - 1, sign, n, ret);
	fill_float(precision, ret, len, n - (long long int)n);
	if (sign)
		ret[0] = '-';
	return (ret);
}

/**
 * @brief 	norminette-induced function split,
 * 			add the integral digits to the return string
 * 
 * @param len 
 * @param sign 
 * @param n 
 * @param ret 
 */
static void	fill_numbers(int len, int sign, long double n, char *ret)
{
	while (--len + 1 - sign)
	{
		if (sign)
			ret[len] = (signed long long) n % 10 * -1 + '0';
		else
			ret[len] = (signed long long) n % 10 + '0';
		n /= 10;
	}
}

static void	fill_float(int prec, char *ret, int len, long double after_point)
{
	if (prec > 0)
		ret[len - prec - 1] = '.';
	while (prec > 0)
	{
		after_point *= 10;
		ret[len - prec] = (unsigned int)after_point % 10 + '0';
		after_point -= (int)after_point;
		--prec;
	}
}

/**
 * @brief count the number of digits in int n
 * 
 * @param n 
 * @param ret 
 * @return int 
 */
static int	digits(signed long long n, int ret)
{
	if (n / 10)
		ret += digits(n / 10, ret);
	return (ret + 1);
}
