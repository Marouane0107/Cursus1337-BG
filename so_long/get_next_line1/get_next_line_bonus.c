/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:43:38 by maouzal           #+#    #+#             */
/*   Updated: 2022/11/19 19:11:54 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *str)
{
	char	*holder;
	int		rd;

	holder = malloc(BUFFER_SIZE + 1);
	if (!holder)
		return (0);
	holder[0] = '\0';
	while (chr(holder))
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
	char	*endline;
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
	endline = malloc(i + 1);
	if (!endline)
		return (0);
	while (str[x] != '\0' && str[x] != '\n')
	{
		endline[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
		endline[x++] = '\n';
	endline[x] = '\0';
	return (endline);
}

char	*rest_val(char *str)
{
	char	*rest;
	int		i;
	int		x;

	i = 0;
	x = 0;
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
	static char	*str[10240];
	char		*buff;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = read_line(fd, str[fd]);
	if (!str[fd])
		return (0);
	buff = end_line(str[fd]);
	str[fd] = rest_val(str[fd]);
	return (buff);
}
