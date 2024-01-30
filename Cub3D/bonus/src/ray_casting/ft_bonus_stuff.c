/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:22:14 by rerayyad          #+#    #+#             */
/*   Updated: 2024/01/19 01:22:15 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	ft_change_door_state(t_mlx *mlx, int *d, int x, int y)
{
	int	p_x;
	int	p_y;

	if (mlx->rays->colision_distance < mlx->player->r * 15)
	{
		x = floor(mlx->rays->hit_y / mlx->cub_size);
		y = floor(mlx->rays->hit_x / mlx->cub_size);
		p_y = floor(mlx->player->x / mlx->cub_size);
		p_x = floor(mlx->player->y / mlx->cub_size);
		if (p_x != x || p_y != y)
		{
			*d = 1;
			if (mlx->new_map[x][y] == 'H')
			{
				mlx->player->space = 0;
				mlx->new_map[x][y] = 'O';
			}
			else if (mlx->new_map[x][y] == 'O')
			{
				mlx->player->space = 0;
				mlx->new_map[x][y] = 'H';
			}
		}
	}
}

void	ft_slime_textures_init(t_mlx *mlx)
{
	int	i;

	mlx->door = malloc(sizeof (char *) * 5);
	if (!mlx->door)
		ft_error_buster(1, mlx);
	mlx->d_animation = 0;
	i = 0;
	mlx->door[0] = "textres/slime00.xpm";
	mlx->door[1] = "textres/slime01.xpm";
	mlx->door[2] = "textres/slime02.xpm";
	mlx->door[3] = "textres/slime03.xpm";
	mlx->door[4] = NULL;
	while (i < 4)
	{
		mlx->d_wall[i] = ft_file_to_image(mlx, mlx->door[i]);
		if (!mlx->d_wall[i++])
			ft_error_buster(6, mlx);
	}
}

void	ft_textures_init(t_mlx *mlx)
{
	mlx->n_wall = ft_file_to_image(mlx, mlx->north_texture);
	if (!mlx->n_wall)
		ft_error_buster(6, mlx);
	mlx->s_wall = ft_file_to_image(mlx, mlx->south_texture);
	if (!mlx->s_wall)
		ft_error_buster(6, mlx);
	mlx->w_wall = ft_file_to_image(mlx, mlx->west_texture);
	if (!mlx->w_wall)
		ft_error_buster(6, mlx);
	mlx->e_wall = ft_file_to_image(mlx, mlx->east_texture);
	if (!mlx->e_wall)
		ft_error_buster(6, mlx);
	ft_animated_textures_init(mlx);
	ft_slime_textures_init(mlx);
}
