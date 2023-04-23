/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docentennm <docentennm@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:04:14 by docentennm        #+#    #+#             */
/*   Updated: 2023/04/23 19:07:45 by docentennm       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

