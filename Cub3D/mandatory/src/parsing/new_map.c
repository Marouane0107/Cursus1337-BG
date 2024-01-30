/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 22:18:53 by maouzal           #+#    #+#             */
/*   Updated: 2024/01/19 07:31:02 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_start(t_mlx *mlx, char *line, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		line += 3;
		while (line[i] && line[i] == ' ')
			i++;
		i += 3;
	}
	else if (type == 2)
	{
		line += 2;
		i = skip_spaces(line);
		i += 2;
	}
	if (line[i] == '\0' || line[i] == '\n')
	{
		if (type == 1)
			ft_error_buster(12, mlx);
		else if (type == 2)
			ft_error_buster(8, mlx);
	}
	return (i);
}

int	get_end(t_mlx *mlx, char *line, int start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!line || !line[start])
		return (start);
	while (line[start + i] && line[start + i] != ' ')
		i++;
	if (line[start + i] == '\0' || line[start + i] == '\n')
		return (i - 1);
	else
	{
		while (line[start + i] && line[start + i] == ' ')
		{
			i++;
			j++;
		}
		if (line[start + i] == '\0' || line[start + i] == '\n')
			return (i - j);
		else
			ft_error_buster(15, mlx);
	}
	return (i);
}

void	copy_map(t_mlx *mlx)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	x = 0;
	j = 0;
	mlx->new_map = malloc(sizeof(char *) * (mlx->map_height + 1));
	if (!mlx->new_map)
		ft_error_buster(1, mlx);
	mlx->new_map[mlx->map_height] = NULL;
	i = skip_vide_line(mlx);
	copy_to_new_map(mlx, i, x, j);
}

void	copy_to_new_map(t_mlx *mlx, int i, int x, int j)
{
	while (mlx->map[i])
	{
		if (mlx->map[i][0] == '\0' || mlx->map[i][0] == '\n')
			break ;
		mlx->new_map[x] = malloc(sizeof(char) * (mlx->map_width + 1));
		if (!mlx->new_map[x])
			ft_error_buster(1, mlx);
		j = 0;
		while (mlx->map[i][j] && mlx->map[i][j] != '\n')
		{
			mlx->new_map[x][j] = mlx->map[i][j];
			if (mlx->new_map[x][j] && (mlx->map[i][j] == 'N'
				|| mlx->map[i][j] == 'S'
				|| mlx->map[i][j] == 'E' || mlx->map[i][j] == 'W'))
				ft_player_pos(mlx, x, j);
			j++;
		}
		while (j < mlx->map_width && j != 0)
			mlx->new_map[x][j++] = ' ';
		mlx->new_map[x][j] = '\0';
		i++;
		x++;
	}
	mlx->new_map[x] = NULL;
}
