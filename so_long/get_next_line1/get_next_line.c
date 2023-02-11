/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:13:58 by maouzal           #+#    #+#             */
/*   Updated: 2022/11/19 19:07:20 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*holder;
	int		rd;

	holder = malloc(BUFFER_SIZE + 1);
	if (!holder)
		return (0);
	holder[0] = '\0';
	while (ft_chr(holder))
	{
		rd = read(fd, holder, BUFFER_SIZE);
		if (rd == -1)
		{
			free(holder);
			if (str)
				free(str);
			return (0);
		}
		if (!rd)
			break ;
		holder[rd] = '\0';
		str = ft_strjoin(str, holder);
	}
	free(holder);
	return (str);
}

char	*end_line(char *str)
{
	char	*n_str;
	int		x;
	int		i;

	x = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	n_str = malloc(i + 1);
	if (!n_str)
		return (0);
	while (str[x] != '\0' && str[x] != '\n')
	{
		n_str[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
		n_str[x++] = '\n';
	n_str[x] = '\0';
	return (n_str);
}

char	*rest_val(char *str)
{
	char	*rest;
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
	{
		free(str);
		return (0);
	}
	rest = malloc(ft_strlen(str) - i);
	if (!rest)
		return (0);
	i++;
	while (str[i] != '\0')
		rest[x++] = str[i++];
	rest[x] = '\0';
	free(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_line(fd, str);
	if (!str)
		return (0);
	buff = end_line(str);
	str = rest_val(str);
	return (buff);
}
