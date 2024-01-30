/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:32:01 by rerayyad          #+#    #+#             */
/*   Updated: 2024/01/04 11:32:04 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_pos_calculator(t_mlx *mlx)
{
	if (mlx->player->m_f || mlx->player->m_b || \
		mlx->player->m_l || mlx->player->m_r)
		ft_move_calculator(mlx);
	if (mlx->player->t_l || mlx->player->t_r)
		ft_turn_calculator(mlx);
}

void	ft_move_front(t_mlx *mlx)
{
	float	x;
	float	y;

	x = mlx->player->x;
	y = mlx->player->y;
	mlx->player->x += cos(mlx->player->rot) * mlx->player->spd;
	if (ft_wall_colision(mlx))
		mlx->player->x = x;
	mlx->player->y += sin(mlx->player->rot) * mlx->player->spd;
	if (ft_wall_colision(mlx))
		mlx->player->y = y;
}

void	ft_move_back(t_mlx *mlx)
{
	float	x;
	float	y;

	x = mlx->player->x;
	y = mlx->player->y;
	mlx->player->x -= cos(mlx->player->rot) * mlx->player->spd;
	if (ft_wall_colision(mlx))
		mlx->player->x = x;
	mlx->player->y -= sin(mlx->player->rot) * mlx->player->spd;
	if (ft_wall_colision(mlx))
		mlx->player->y = y;
}

void	ft_move_left(t_mlx *mlx)
{
	float	x;
	float	y;

	x = mlx->player->x;
	y = mlx->player->y;
	mlx->player->x -= cos(mlx->player->rot + M_PI_2) * mlx->player->spd;
	if (ft_wall_colision(mlx))
		mlx->player->x = x;
	mlx->player->y -= sin(mlx->player->rot + M_PI_2) * mlx->player->spd;
	if (ft_wall_colision(mlx))
		mlx->player->y = y;
}

void	ft_move_right(t_mlx *mlx)
{
	float	x;
	float	y;

	x = mlx->player->x;
	y = mlx->player->y;
	mlx->player->x += cos(mlx->player->rot + M_PI_2) * mlx->player->spd;
	if (ft_wall_colision(mlx))
		mlx->player->x = x;
	mlx->player->y += sin(mlx->player->rot + M_PI_2) * mlx->player->spd;
	if (ft_wall_colision(mlx))
		mlx->player->y = y;
}
