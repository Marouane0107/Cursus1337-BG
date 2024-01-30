/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_selection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:09:17 by maouzal           #+#    #+#             */
/*   Updated: 2024/01/17 15:10:01 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

t_img	ft_animated_wall_select(t_mlx *mlx)
{
	if (mlx->animation % (4 * ANIMATION) == 0)
		mlx->animation = 0;
	return (*mlx->a_wall[mlx->animation++ / ANIMATION]);
}

t_img	ft_animated_slime_select(t_mlx *mlx)
{
	if (mlx->d_animation % (4 * ANIMATION) == 0)
		mlx->d_animation = 0;
	return (*mlx->d_wall[mlx->d_animation++ / ANIMATION]);
}

t_img	ft_animated_door_select(t_mlx *mlx)
{
	if (mlx->d_animation % (4 * ANIMATION) == 0)
		mlx->d_animation = 0;
	return (*mlx->d_wall[mlx->d_animation++ / ANIMATION]);
}

t_img	ft_texture_selector(t_mlx *mlx)
{
	if (mlx->rays->type == 'A')
		return (ft_animated_wall_select(mlx));
	else if (mlx->rays->type == 'H')
		return (ft_animated_slime_select(mlx));
	if (mlx->rays->heading == 'N')
		return (*mlx->n_wall);
	else if (mlx->rays->heading == 'S')
		return (*mlx->s_wall);
	else if (mlx->rays->heading == 'E')
		return (*mlx->e_wall);
	else
		return (*mlx->w_wall);
}
