/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_itoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:40:46 by maouzal           #+#    #+#             */
/*   Updated: 2023/02/09 15:31:54 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_n(int n)
{
	int	len;
	int	a;

	a = n;
	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / 10;
		if (n % 10 != 0)
			len++;
		if (n % 10 == 0 && n > 9)
			len++;
	}
	if (n % 10 < 10 && a != 0)
		len++;
	return (len + 1);
}

static void	ft_it(int n, char *p, int i, int len)
{
	i = 0;
	while (n != 0)
	{
		i = n % 10;
		n = n / 10;
		if (i >= 0)
			p[len--] = i + '0';
	}
}

char	*ft_itoa(int n)
{
	char	*p;
	int		x;
	int		len;
	int		i;

	i = n;
	len = ft_count_n(n);
	x = 0;
	p = malloc(len * sizeof(char));
	if (!(p))
		return (0);
	if (n == 0)
	{
		p[x] = '0';
		p[x + 1] = '\0';
	}
	len -= 1;
	p[len--] = '\0';
	ft_it(i, p, i, len);
	return (p);
}

void	ft_putstr(char *s)
{
	int	x;

	x = 0;
	if (s)
	{
		while (s[x] != '\0')
		{
			write(1, &s[x], 1);
			x++;
		}
	}
}

void	ft_print(int n)
{
	char	*s;

	s = ft_itoa(n);
	ft_putstr(s);
	free(s);
	write(1, "\n", 2);
}
