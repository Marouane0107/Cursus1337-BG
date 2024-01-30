/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texter_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:08:06 by maouzal           #+#    #+#             */
/*   Updated: 2024/01/19 02:35:44 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

int	fill_texter_color(t_mlx *mlx, char *str)
{
	while (*str == ' ')
		str++;
	if (fill_texter(mlx, str) == 0)
		return (0);
	else if (ft_strnstr(str, "EA ", 3))
	{
		if (mlx->east_texture)
			ft_error_buster(14, mlx);
		mlx->east_texture = ft_substr(str, get_start(mlx, str, 1), \
		get_end(mlx, str, get_start(mlx, str, 1)));
	}
	else if (fill_color(mlx, str) == 0)
		return (0);
	else
		return (1);
	return (0);
}

int	fill_texter(t_mlx *mlx, char *str)
{
	if (ft_strnstr(str, "NO ", 3))
	{
		if (mlx->north_texture)
			ft_error_buster(14, mlx);
		mlx->north_texture = ft_substr(str, get_start(mlx, str, 1), \
		get_end(mlx, str, get_start(mlx, str, 1)));
		return (0);
	}
	else if (ft_strnstr(str, "SO ", 3))
	{
		if (mlx->south_texture)
			ft_error_buster(14, mlx);
		mlx->south_texture = ft_substr(str, get_start(mlx, str, 1), \
		get_end(mlx, str, get_start(mlx, str, 1)));
		return (0);
	}
	else if (ft_strnstr(str, "WE ", 3))
	{
		if (mlx->west_texture)
			ft_error_buster(14, mlx);
		mlx->west_texture = ft_substr(str, get_start(mlx, str, 1), \
		get_end(mlx, str, get_start(mlx, str, 1)));
		return (0);
	}
	return (1);
}

int	fill_color(t_mlx *mlx, char *str)
{
	if (ft_strnstr(str, "C ", 2))
	{
		if (mlx->c_color)
			ft_error_buster(14, mlx);
		mlx->c_color = ft_substr(str, get_start(mlx, str, 2), \
		ft_strlen(str) - get_start(mlx, str, 2) - 1);
		return (0);
	}
	else if (ft_strnstr(str, "F ", 2))
	{
		if (mlx->f_color)
			ft_error_buster(14, mlx);
		mlx->f_color = ft_substr(str, get_start(mlx, str, 2), \
		ft_strlen(str) - get_start(mlx, str, 2) - 1);
		return (0);
	}
	else
		return (1);
}

void	fill_texter_map(int i, int j, int size, t_mlx *mlx)
{
	int	x;

	while (mlx->full_file[i])
	{
		if (fill_texter_color(mlx, mlx->full_file[i]) == 1)
		{
			if (mlx->full_file[i][0] != '\0' && mlx->full_file[i][0] != '\n'
				&& texter_color_exist(mlx))
			{
				x = skip_spaces(mlx->full_file[i]);
				if (mlx->full_file[i][x] != '\0' &&
					mlx->full_file[i][x] != '\n')
					ft_error_buster(15, mlx);
			}
			if (!mlx->full_file[i + 1] && !texter_color_exist(mlx))
				mlx->map[j++] = ft_substr(mlx->full_file[i], 0, \
					ft_strlen(mlx->full_file[i]));
			else if (!texter_color_exist(mlx))
				mlx->map[j++] = ft_substr(mlx->full_file[i], 0, \
				ft_strlen(mlx->full_file[i]) - 1);
		}
		i++;
	}
	if (j <= size)
		mlx->map[j] = NULL;
}

void	get_texters(t_mlx *mlx)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = get_map_size(mlx);
	if (size <= 2)
		ft_error_buster(10, mlx);
	mlx->map = ft_calloc(sizeof(char *), (size + 1));
	if (!mlx->map)
		ft_error_buster(1, mlx);
	mlx->map[size] = NULL;
	fill_texter_map(i, j, size, mlx);
}
