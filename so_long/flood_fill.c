/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:35:59 by maouzal           #+#    #+#             */
/*   Updated: 2023/02/11 18:15:00 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fl_fill(t_data *p, int i, int j)
{
	if (p->cpy[i][j] != 'P' && p->cpy[i][j] != 'E' &&
		p->cpy[i][j] != 'C' && p->cpy[i][j] != '0')
		return ;
	else if (p->cpy[i][j] == 'E')
	{
		p->cpy[i][j] = 'v';
		return ;
	}
	p->cpy[i][j] = '+';
	fl_fill(p, i, j + 1);
	fl_fill(p, i, j - 1);
	fl_fill(p, i + 1, j);
	fl_fill(p, i - 1, j);
}

void	check_path(t_data *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->cpy[i])
	{
		j = 0;
		while (p->cpy[i][j])
		{
			if (p->cpy[i][j] == 'E' || p->cpy[i][j] == 'C')
			{
				write(2, "ERROR\nUnvalid path !! ", 23);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
