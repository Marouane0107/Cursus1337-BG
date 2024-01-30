/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:07:22 by maouzal           #+#    #+#             */
/*   Updated: 2024/01/19 03:37:27 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_file_parser(t_mlx *mlx, char *av)
{
	get_file(mlx, av);
	is_deplecate(mlx);
	get_texters(mlx);
	if (!mlx->east_texture || !mlx->west_texture
		|| !mlx->south_texture || !mlx->north_texture)
		ft_error_buster(6, mlx);
	colors_existence(mlx);
	check_colors_format(mlx->c_color, mlx, 'c');
	check_colors_format(mlx->f_color, mlx, 'f');
}

void	is_deplecate(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->full_file[i])
	{
		if (!ft_strncmp(mlx->full_file[i], "NO", 2)
			|| !ft_strncmp(mlx->full_file[i], "SO", 2)
			|| !ft_strncmp(mlx->full_file[i], "WE", 2)
			|| !ft_strncmp(mlx->full_file[i], "EA", 2)
			|| !ft_strncmp(mlx->full_file[i], "C ", 2)
			|| !ft_strncmp(mlx->full_file[i], "F ", 2))
		{
			j = i + 1;
			while (mlx->full_file[j])
			{
				if (!ft_strncmp(mlx->full_file[i], mlx->full_file[j], 2))
					ft_error_buster(14, mlx);
				j++;
			}
		}
		i++;
	}
}

void	get_file_size(t_mlx *mlx, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_buster(13, mlx);
	line = m_get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = m_get_next_line(fd);
	}
	free(line);
	close(fd);
	if (i == 0)
		ft_error_buster(13, mlx);
	mlx->full_file = malloc(sizeof(char *) * (i + 1));
	mlx->full_file[i] = NULL;
}

void	get_file(t_mlx *mlx, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_buster(13, mlx);
	get_file_size(mlx, file);
	line = m_get_next_line(fd);
	fill_file(mlx, line, fd);
	close(fd);
}

void	fill_file(t_mlx *mlx, char *line, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line)
	{
		mlx->full_file[i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!mlx->full_file[i])
			ft_error_buster(1, mlx);
		j = 0;
		while (line[j])
		{
			mlx->full_file[i][j] = line[j];
			j++;
		}
		mlx->full_file[i][j] = '\0';
		free(line);
		line = m_get_next_line(fd);
		i++;
	}
}
