/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_janitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 09:57:02 by rerayyad          #+#    #+#             */
/*   Updated: 2024/01/14 18:39:45 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_all(t_mlx *mlx)
{
	if (mlx->east_texture)
		free(mlx->east_texture);
	if (mlx->west_texture)
		free(mlx->west_texture);
	if (mlx->south_texture)
		free(mlx->south_texture);
	if (mlx->north_texture)
		free(mlx->north_texture);
	if (mlx->c_color)
		free(mlx->c_color);
	if (mlx->f_color)
		free(mlx->f_color);
	if (mlx->full_file)
		ft_free(mlx->full_file);
	if (mlx->new_map)
		ft_free(mlx->new_map);
	if (mlx->map)
		ft_free(mlx->map);
}

void	ft_error_buster(int id, t_mlx *mlx)
{
	(void)mlx;
	if (id == 1)
		ft_putstr_fd("\033[0;31mError: Unable to allocate memory\n", 2);
	else if (id == 2)
		ft_putstr_fd("\033[0;31mError: MiniLibX initialization failed\n", 2);
	else if (id == 3)
	{
		ft_putstr_fd("\033[0;31mError: Wrong number of arguments\n", 2);
		ft_putstr_fd("\033[0;32m\tUsage: ./cub3D <mapname>.cub\n", 2);
	}
	else if (id == 4 || id == 5)
	{
		ft_putstr_fd("\033[0;31mError: Wrong file format\n", 2);
		ft_putstr_fd("\033[0;32m\tUsage: ./cub3D <mapname>.cub\n", 2);
	}
	else
		ft_error_buster2(id);
	printf("\033[0m");
	exit (1);
}

void	ft_error_buster2(int id)
{
	if (id == 6)
		ft_putstr_fd("\033[0;31mError: Texture not found\n", 2);
	else if (id == 7)
		ft_putstr_fd("\033[0;31mError: Missing color\n", 2);
	else if (id == 8)
		ft_putstr_fd("\033[0;31mError: Invalid color format\n", 2);
	else if (id == 9)
		ft_putstr_fd("\033[0;31mError: Invalid color range\n", 2);
	else if (id == 10)
		ft_putstr_fd("\033[0;31mError: Invalid Map\n", 2);
	else if (id == 11)
		ft_putstr_fd("\033[0;31mError: Invalid Player\n", 2);
	else if (id == 12)
		ft_putstr_fd("\033[0;31mError: Invalid texture\n", 2);
	else if (id == 13)
		ft_putstr_fd("\033[0;31mError: Invalid file\n", 2);
	else if (id == 14)
		ft_putstr_fd("\033[0;31mError: Texture or color duplicate found\n", 2);
	else if (id == 15)
		ft_putstr_fd("\033[0;31mError: Wrong format\n", 2);
}
