/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:24:31 by maouzal           #+#    #+#             */
/*   Updated: 2023/02/08 23:20:25 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

void	struct_init(t_data *s)
{
	s->i = 0;
	s->j = 0;
	s->c = 0;
	s->p = 0;
	s->e = 0;
}

void	end_game(int i, int j, t_data *p)
{
	if (p->map[i][j] == 'P' && p->map[i - 1][j] == 'E' && p->c == 0)
	{
		write(1, "You won ;) ", 11);
		exit(0);
	}
	else if (p->map[i][j] == 'P' && p->map[i + 1][j] == 'E' && p->c == 0)
	{
		write(1, "You won ;) ", 11);
		exit(0);
	}
	else if (p->map[i][j] == 'P' && p->map[i][j + 1] == 'E' && p->c == 0)
	{
		write(1, "You won ;) ", 11);
		exit(0);
	}
	else if (p->map[i][j] == 'P' && p->map[i][j - 1] == 'E' && p->c == 0)
	{
		write(1, "You won ;) ", 11);
		exit(0);
	}
}

int	leave(void)
{
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*p;

	p = malloc(sizeof(t_data));
	p->move_count = 0;
	p->mlx = mlx_init();
	struct_init(p);
	check_arg(argc, argv[1]);
	p->fd = open(argv[1], O_RDONLY);
	p->map = read_map(p->fd, p);
	check_map_size(p);
	p->length = check_map_dimension(p);
	p->width = ft_strlen(p->map[0]);
	check_map_wall(p, p->length, p->width);
	check_map_characters(p);
	p->c = check_map_min(p);
	player_ps(p);
	fl_fill(p, p->y, p->x);
	check_path(p);
	put_emages(p);
	p->mlx_win = mlx_new_window(p->mlx, p->width * 50, p->length * 50,
			"So_long");
	mlx_hook(p->mlx_win, 2, 0, move, p);
	mlx_hook(p->mlx_win, 17, 0, leave, p);
	loop_emage(p, 0, 0);
	mlx_loop(p->mlx);
}
