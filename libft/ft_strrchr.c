/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:04:35 by maouzal           #+#    #+#             */
/*   Updated: 2022/10/13 13:21:43 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	w;

	w = 0;
	while (s[w] != '\0')
		w++;
	if ((char)c == '\0')
		return ((char *)&s[w]);
	while (w >= 0)
	{
		if (s[w] == (char)c)
			return ((char *)&s[w]);
		w--;
	}
	return (0);
}
