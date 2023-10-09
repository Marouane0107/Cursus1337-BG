/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:56:18 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/25 22:17:39 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	ft_maxlong(const char *str, long x, long res, long w)
{
	while (str[x] >= '0' && str[x] <= '9')
	{
		if (res * 10 + str[x] - 48 < res)
		{
			if (w == -1)
				return (0);
			else
				return (-1);
		}
		res = res * 10 + str[x] - 48;
		x++;
	}
	return (res * w);
}

int	ft_atoi(const char	*str)
{
	long	x;
	long	w;
	long	res;

	res = 0;
	x = 0;
	w = 1;
	while (str[x] == '\t' || str[x] == '\n' || str[x] == '\v'
		|| str[x] == '\f' || str[x] == '\r' || str[x] == ' ')
		x++;
	if (str[x] == '-')
	{
		w = -1;
		x++;
	}
	else if (str[x] == '+')
	{
			w = 1;
			x++;
	}
	return (ft_maxlong(str, x, res, w));
}
