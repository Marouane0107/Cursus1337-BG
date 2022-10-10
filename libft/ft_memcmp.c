/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:48:42 by maouzal           #+#    #+#             */
/*   Updated: 2022/10/10 06:20:59 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	size_t	x;
	unsigned char	*p1;
	unsigned char *p2;

	p1 = (unsigned char	*)s1;
	p2 = (unsigned char	*)s2;
	x = 0;
	while (x < n)
	{
		if (p1[x] != p2[x])
			return (p1[x] - p2[x]);
		x++;
	}
	return (p1[x] - p2[x]);
}
