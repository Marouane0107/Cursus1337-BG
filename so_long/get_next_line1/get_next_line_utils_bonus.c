/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:51:54 by maouzal           #+#    #+#             */
/*   Updated: 2022/11/18 23:45:08 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(const char *s)
{
	char			*ns;
	unsigned int	len;
	unsigned int	x;

	len = ft_strlen(s) + 1;
	ns = malloc(len);
	if (!ns)
		return (0);
	x = 0;
	while (x < len)
	{
		ns[x] = s[x];
		x++;
	}
	return (ns);
}

int	chr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*ns;
	unsigned int	x;
	unsigned int	i;

	x = 0;
	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	ns = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ns)
		return (0);
	while (s1[i] != '\0')
	{
		ns[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		ns[i] = s2[x];
		i++;
		x++;
	}
	ns[i] = '\0';
	free(s1);
	return (ns);
}
