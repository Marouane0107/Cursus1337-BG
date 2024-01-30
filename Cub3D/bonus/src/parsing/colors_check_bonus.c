/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:07:45 by maouzal           #+#    #+#             */
/*   Updated: 2024/01/19 07:01:08 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	check_color_arg(char *tmp, t_mlx *mlx)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (tmp[i] == ',' || tmp[i] == '\0')
		ft_error_buster(8, mlx);
	while (tmp[i])
	{
		if (tmp[i] == ' ')
		{
			flag = 1;
			while (tmp[i] == ' ')
				i++;
			if (flag == 1 && tmp[i] != '\0' && tmp[i] != ',')
				ft_error_buster(8, mlx);
			if (!tmp[i])
				break ;
		}
		i++;
	}
}

void	check_colors_format(char *str, t_mlx *mlx, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != ',' && str[i] != '0'
			&& str[i] != '1' && str[i] != '2' && str[i] != '3'
			&& str[i] != '4' && str[i] != '5' && str[i] != '6'
			&& str[i] != '7' && str[i] != '8' && str[i] != '9')
			ft_error_buster(8, mlx);
		if (str[i] == ',')
		{
			j++;
			if (str[i + 1] == ',')
				ft_error_buster(8, mlx);
		}
		i++;
	}
	if (j != 2)
		ft_error_buster(8, mlx);
	check_colors_range(str, mlx, c);
}

void	ft_color_assigner(t_mlx *mlx, char c, int a, int i)
{
	if (c == 'c')
	{
		if (i == 0)
			mlx->c_color_int += a * 256 * 256;
		if (i == 1)
			mlx->c_color_int += a * 256;
		if (i == 2)
			mlx->c_color_int += a;
	}
	else if (c == 'f')
	{
		if (i == 0)
			mlx->f_color_int += a * 256 * 256;
		if (i == 1)
			mlx->f_color_int += a * 256;
		if (i == 2)
			mlx->f_color_int += a;
	}
}

void	colors_range(t_mlx *mlx, char *tmp, int i, char c)
{
	int		a;
	size_t	k;
	int		j;
	char	*str;

	k = 0;
	j = skip_spaces(tmp);
	while (tmp[j] == '0' && tmp[j + 1] != '\0' && tmp[j + 1] != ' ')
		j++;
	check_color_arg(tmp + j, mlx);
	while (tmp[j])
	{
		if (tmp[j] != ' ')
			k++;
		j++;
	}
	a = ft_atoi(tmp);
	str = ft_itoa(a);
	if (k != ft_strlen(str) && a != 0)
		ft_error_buster(8, mlx);
	if (a < 0 || a > 255)
		ft_error_buster(9, mlx);
	free(str);
	ft_color_assigner(mlx, c, a, i);
	free(tmp);
}

void	check_colors_range(char	*str, t_mlx *mlx, char c)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i] != ',' && str[i] != '\0')
		i++;
	tmp = ft_substr(str, 0, i);
	colors_range(mlx, tmp, 0, c);
	i++;
	j = i;
	while (str[i] != ',')
		i++;
	tmp = ft_substr(str, j, i - j);
	colors_range(mlx, tmp, 1, c);
	i++;
	j = i;
	while (str[i] != '\0')
		i++;
	tmp = ft_substr(str, j, i - j);
	if (tmp[0] == '\0')
		ft_error_buster(8, mlx);
	colors_range(mlx, tmp, 2, c);
}
