/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read-map-arg_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:37:42 by maouzal           #+#    #+#             */
/*   Updated: 2023/02/11 18:13:56 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	emty_line(char *holder)
{
	int	i;

	i = 0;
	while (holder[i])
	{
		if ((holder[i] == '\n' && holder[i + 1] == '\n') || (holder[0] == '\n'
				|| holder[ft_strlen(holder) - 1] == '\n'))
		{
			write(2, "Error\nUnvalude map! (emty line) ", 33);
			exit(1);
		}
		i++;
	}
}

char	**read_map(int fd, t_data *p)
{
	char	*line;
	char	*holder;

	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nVide map !! ", 19);
		exit(1);
	}
	while (line)
	{
		holder = ft_strjoin(holder, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	emty_line(holder);
	p->map = ft_split(holder, '\n');
	p->cpy = ft_split(holder, '\n');
	free(holder);
	return (p->map);
}

void	check_arg(int argc, char *argv)
{
	int	x;

	if (argc == 1)
	{
		write(2, "Error\nMap not found", 20);
		exit(1);
	}
	if (argc > 2)
	{
		write(2, "Error\nTo many argument", 23);
		exit(1);
	}
	x = ft_strlen(argv);
	x--;
	if (argv[x] != 'r' && argv[x - 1] != 'e' && argv[x - 2] != 'b' && argv[x
			- 3] != '.')
	{
		write(2, "Error\nUnvalide map (.ber)!", 27);
		exit(0);
	}
}

void	player_ps(t_data *p)
{
	int	i;
	int	j;

	i = 0;
	p->x = 0;
	p->y = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'P')
			{
				p->x = j;
				p->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
