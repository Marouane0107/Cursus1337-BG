/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keylogger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:52:57 by rerayyad          #+#    #+#             */
/*   Updated: 2023/12/21 17:52:58 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

int	ft_cross(int key, t_mlx *mlx)
{
	(void)key;
	(void)mlx;
	exit (0);
}

int	ft_key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		mlx->player->m_f = 1;
	else if (keycode == KEY_S)
		mlx->player->m_b = 1;
	else if (keycode == KEY_A)
		mlx->player->m_l = 1;
	else if (keycode == KEY_D)
		mlx->player->m_r = 1;
	else if (keycode == KEY_L_A)
		mlx->player->t_l = 1;
	else if (keycode == KEY_R_A)
		mlx->player->t_r = 1;
	else if (keycode == KEY_SPACE)
		mlx->player->space = 1;
	else if (keycode == ESCAPE_KEY)
		exit (0);
	return (0);
}

int	ft_key_release(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		mlx->player->m_f = 0;
	else if (keycode == KEY_S)
		mlx->player->m_b = 0;
	else if (keycode == KEY_A)
		mlx->player->m_l = 0;
	else if (keycode == KEY_D)
		mlx->player->m_r = 0;
	else if (keycode == KEY_L_A)
		mlx->player->t_l = 0;
	else if (keycode == KEY_R_A)
		mlx->player->t_r = 0;
	else if (keycode == KEY_SPACE)
		mlx->player->space = 0;
	return (0);
}
