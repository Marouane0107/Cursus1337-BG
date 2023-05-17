/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:24:35 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/17 02:24:39 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	x;

	x = 0;
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strdup(const char *s1)
{
	char			*s2;
	unsigned int	len;
	unsigned int	x;

	x = 0;
	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (!s2)
		return (0);
	while (x < len)
	{
		s2[x] = s1[x];
		x++;
	}
	x--;
	if (s2[x] != '\0')
	{
		x++;
		s2[x] = '\0';
	}
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*s3;
	unsigned int	x;
	unsigned int	i;

	x = 0;
	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(s3))
		return (0);
	while (s1[i] != '\0')
	{
		s3[x] = s1[i];
		i++;
		x++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[x++] = s2[i++];
	}
	s3[x] = '\0';
	free(s1);
	return (s3);
}

int	ft_chr(char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == '\n')
			return (0);
		x++;
	}
	return (1);
}
