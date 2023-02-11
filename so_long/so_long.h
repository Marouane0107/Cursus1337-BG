/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:35:51 by maouzal           #+#    #+#             */
/*   Updated: 2023/02/09 17:21:05 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "get_next_line1/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char	**map;
	char	**cpy;
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*wall;
	void	*enemy;
	void	*ring;
	void	*exit;
	void	*grass;
	int		length;
	int		width;
	int		move_count;
	int		fd;
	int		x;
	int		y;
	int		i;
	int		j;
	int		c;
	int		e;
	int		p;
}			t_data;

void		exit_right(int i, int j, t_data *p);
void		exit_left(int i, int j, t_data *p);
void		exit_down(int i, int j, t_data *p);
void		exit_up(int i, int j, t_data *p);
int			ft_cmp(char *s1, char *s2);
char		**ft_split(char const *s, char c);
void		check_map_size(t_data *p);
int			check_map_dimension(t_data *p);
void		check_map_wall(t_data *p, int l_m, int width);
void		check_map_characters(t_data *p);
int			check_map_min(t_data *s);
int			move(int k, t_data *p);
void		put_emages(t_data *p);
void		loop_emage(t_data *p, int x, int y);
char		**read_map(int fd, t_data *p);
void		check_arg(int argc, char *argv);
char		*ft_itoa(int n);
void		ft_putstr(char *s);
void		ft_print(int n);
void		player_ps(t_data *p);
void		fl_fill(t_data *p, int i, int j);
void		check_path(t_data *p);

#endif