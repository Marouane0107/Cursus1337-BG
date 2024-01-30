/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:38:19 by rerayyad          #+#    #+#             */
/*   Updated: 2024/01/14 17:28:53 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_img	*ft_file_to_image(t_mlx *mlx, char *path)
{
	t_img	*texture;

	texture = malloc (sizeof (t_img));
	if (!texture)
		ft_error_buster(1, mlx);
	texture->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path,
			&texture->width, &texture->len);
	if (!texture->img)
		ft_error_buster(6, mlx);
	texture->id = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->len, &texture->endian);
	if (!texture->id)
		ft_error_buster(6, mlx);
	return (texture);
}

t_img	ft_texture_selector(t_mlx *mlx)
{
	if (mlx->rays->heading == 'N')
		return (*mlx->n_wall);
	else if (mlx->rays->heading == 'S')
		return (*mlx->s_wall);
	else if (mlx->rays->heading == 'E')
		return (*mlx->e_wall);
	else
		return (*mlx->w_wall);
}

void	ft_render_skyfloor(t_mlx *mlx, int i, t_pos width_n_height, int n)
{
	t_pos	coordinates;
	int		color;
	char	c;

	c = mlx->rays->heading;
	if (!n)
	{
		coordinates.x = i;
		coordinates.y = 0;
		width_n_height.y = (mlx->win_y / 2) - (width_n_height.y / 2);
		color = mlx->c_color_int;
		mlx->rays->heading = 'C';
	}
	else
	{
		coordinates.x = i;
		coordinates.y = (mlx->win_y / 2) - (width_n_height.y / 2)
			+ width_n_height.y;
		width_n_height.y = (mlx->win_y - (coordinates.y));
		color = mlx->f_color_int;
		mlx->rays->heading = 'F';
	}
	mlx->rays->heading = c;
	ft_draw_rectangle(mlx, &coordinates, width_n_height, color);
}

void	ft_draw_textured_wall(t_mlx *mlx, t_pos *coordinates,
		t_pos width_n_height)
{
	int		x;
	int		y;
	float	scale;
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (!pos)
		ft_error_buster(1, mlx);
	x = coordinates->x;
	pos_x_init(mlx, pos);
	scale = (mlx->texture.width / width_n_height.y);
	pos->y = 0;
	if (mlx->win_y < width_n_height.y)
	{
		coordinates->y = 0;
		pos->y = ((width_n_height.y - mlx->win_y) / 2) * scale;
	}
	y = coordinates->y;
	while (y < coordinates->y + width_n_height.y && y < mlx->win_y)
	{
		pos->y += scale;
		ft_put_pixel(mlx, x, y++, ft_my_mlx_pixel_get(mlx, pos->x, pos->y));
	}
	free (pos);
}

void	pos_x_init(t_mlx *mlx, t_pos *pos)
{
	if (mlx->rays->s == 'h')
		pos->x = ((mlx->rays->hit_x / mlx->cub_size)
				- (int)(mlx->rays->hit_x / mlx->cub_size)) * mlx->texture.width;
	else
		pos->x = ((mlx->rays->hit_y / mlx->cub_size)
				- (int)(mlx->rays->hit_y / mlx->cub_size)) * mlx->texture.width;
}
