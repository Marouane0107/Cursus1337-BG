/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rerayyad <rerayyad@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:26:16 by rerayyad          #+#    #+#             */
/*   Updated: 2024/01/13 21:39:02 by rerayyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

void	arg_check(int ac, char **av)
{
	int	i;

	i = ft_strlen(av[1]) - 3;
	if (ac != 2)
		ft_error_buster(3, NULL);
	if (av[1][i] != 'c' || av[1][i + 1] != 'u'
		|| av[1][i + 2] != 'b' || av[1][i + 3] != '\0')
		ft_error_buster(4, NULL);
	if (ft_strlen(av[1]) < 4)
		ft_error_buster(5, NULL);
}

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	arg_check(ac, av);
	mlx = ft_data_init(av);
	ft_canvas_maker(mlx);
	return (0);
}
