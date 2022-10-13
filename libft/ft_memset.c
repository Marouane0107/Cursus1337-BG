/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:32:13 by maouzal           #+#    #+#             */
/*   Updated: 2022/10/13 13:13:22 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	x;
	char	*p;

	p = b;
	x = 0;
	while (x < len)
	{
		p[x] = c;
		x++;
	}
	return (p);
}
