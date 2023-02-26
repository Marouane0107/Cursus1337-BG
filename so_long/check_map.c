/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:56:40 by maouzal           #+#    #+#             */
/*   Updated: 2023/02/26 17:19:54 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_size(t_data *p)
{
	int				i;
	int				j;
	unsigned int	first_len;

	first_len = 0;
	i = 0;
	j = 0;
	first_len = ft_strlen(p->map[i]);
	i += 1;
	while (p->map[i] != '\0')
	{
		if (first_len != ft_strlen(p->map[i]))
		{
			write(2, "Error\nThe map must be rectangular!! ", 37);
			exit(1);
		}
		i++;
	}
}

int	check_map_dimension(t_data *p)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (p->map[i] != '\0')
		i++;
	while (p->map[x])
	{
		while (p->map[x][j])
		{
			if (p->map[x][j] == '\n')
			{
				write(2, "Error\nUnvalude map! ", 21);
				exit(1);
			}
			j++;
		}
		j = 0;
		x++;
	}
	return (i);
}

void	check_map_wall(t_data *p, int l_m, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (p->map[0][i] != '1' || p->map[l_m - 1][i] != '1')
		{
			write(2, "Error\nThe map must be surrounded by walls", 42);
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < l_m)
	{
		if (p->map[i][0] != '1' || p->map[i][width - 1] != '1')
		{
			write(2, "Error\nThe map must be surrounded by walls", 42);
			exit(1);
		}
		i++;
	}
}

void	check_map_characters(t_data *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p->map[i])
	{
		while (p->map[i][j])
		{
			if (p->map[i][j] != '1' && p->map[i][j] != '0' &&
				p->map[i][j] != 'C' && p->map[i][j] != 'P' &&
				p->map[i][j] != 'E')
			{
				write(2, "Error\nThe map most only conten these (C,P,E,0,1)",
					49);
				exit(1);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	check_map_min(t_data *s)
{
	while (s->map[s->i])
	{
		while (s->map[s->i][s->j])
		{
			if (s->map[s->i][s->j] == 'C')
				s->c += 1;
			if (s->map[s->i][s->j] == 'P')
				s->p += 1;
			if (s->map[s->i][s->j] == 'E')
				s->e += 1;
			s->j++;
		}
		s->j = 0;
		s->i++;
	}
	if (s->c < 1 || s->e != 1 || s->p != 1)
	{
		write(2,
			"Error\nThe map must contain one of E and P and at least one C ",
			62);
		exit(1);
	}
	return (s->c);
}
