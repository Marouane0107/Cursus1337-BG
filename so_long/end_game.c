/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:04:12 by maouzal           #+#    #+#             */
/*   Updated: 2023/02/09 21:24:18 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_left(int i, int j, t_data *p)
{
	if (p->map[i][j] == 'P' && p->map[i][j - 1] == 'E' && p->c == 0)
	{
		write(1, "You won ;) ", 12);
		exit(0);
	}
}

void	exit_right(int i, int j, t_data *p)
{
	if (p->map[i][j] == 'P' && p->map[i][j + 1] == 'E' && p->c == 0)
	{
		write(1, "You won ;) ", 12);
		exit(0);
	}
}

void	exit_down(int i, int j, t_data *p)
{
	if (p->map[i][j] == 'P' && p->map[i + 1][j] == 'E' && p->c == 0)
	{
		write(1, "You won ;) ", 12);
		exit(0);
	}
}

void	exit_up(int i, int j, t_data *p)
{
	if (p->map[i][j] == 'P' && p->map[i - 1][j] == 'E' && p->c == 0)
	{
		write(1, "You won ;) ", 12);
		exit(0);
	}
}
