/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mevment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:44:47 by maouzal           #+#    #+#             */
/*   Updated: 2023/02/11 17:55:40 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *p, int i, int j)
{
	while (p->map[++i])
	{
		j = -1;
		while (p->map[i][++j])
		{
			if (p->map[i][j] == 'P' && p->map[i][j + 1] == '0')
			{
				p->map[i][j] = '0';
				p->map[i][j + 1] = 'P';
				p->move_count++;
				ft_print(p->move_count);
				return ;
			}
			if (p->map[i][j] == 'P' && p->map[i][j + 1] == 'C')
			{
				p->map[i][j] = '0';
				p->map[i][j + 1] = 'P';
				p->c--;
				p->move_count++;
				ft_print(p->move_count);
				return ;
			}
			exit_right(i, j, p);
		}
	}
}

void	move_down(t_data *p, int i, int j)
{
	while (p->map[++i])
	{
		j = -1;
		while (p->map[i][++j])
		{
			if (p->map[i][j] == 'P' && p->map[i + 1][j] == '0')
			{
				p->map[i][j] = '0';
				p->map[i + 1][j] = 'P';
				p->move_count++;
				ft_print(p->move_count);
				return ;
			}
			if (p->map[i][j] == 'P' && p->map[i + 1][j] == 'C')
			{
				p->map[i][j] = '0';
				p->map[i + 1][j] = 'P';
				p->c--;
				p->move_count++;
				ft_print(p->move_count);
				return ;
			}
			exit_down(i, j, p);
		}
	}
}

void	move_left(t_data *p, int i, int j)
{
	while (p->map[++i])
	{
		j = -1;
		while (p->map[i][++j])
		{
			if (p->map[i][j] == 'P' && p->map[i][j - 1] == '0')
			{
				p->map[i][j] = '0';
				p->map[i][j - 1] = 'P';
				p->move_count++;
				ft_print(p->move_count);
				return ;
			}
			else if (p->map[i][j] == 'P' && p->map[i][j - 1] == 'C')
			{
				p->map[i][j] = '0';
				p->map[i][j - 1] = 'P';
				p->c--;
				p->move_count++;
				ft_print(p->move_count);
				return ;
			}
			exit_left(i, j, p);
		}
	}
}

void	move_up(t_data *p, int i, int j)
{
	while (p->map[++i])
	{
		j = -1;
		while (p->map[i][++j])
		{
			if (p->map[i][j] == 'P' && p->map[i - 1][j] == '0')
			{
				p->map[i][j] = '0';
				p->map[i - 1][j] = 'P';
				p->move_count++;
				ft_print(p->move_count);
				return ;
			}
			else if (p->map[i][j] == 'P' && p->map[i - 1][j] == 'C')
			{
				p->map[i][j] = '0';
				p->map[i - 1][j] = 'P';
				p->c--;
				p->move_count++;
				ft_print(p->move_count);
				return ;
			}
			exit_up(i, j, p);
		}
	}
}

int	move(int k, t_data *p)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (k == 126)
		move_up(p, i, j);
	if (k == 124)
		move_right(p, i, j);
	if (k == 123)
		move_left(p, i, j);
	if (k == 125)
		move_down(p, i, j);
	if (k == 53)
	{
		free(p);
		exit(0);
	}
	loop_emage(p, 0, 0);
	return (k);
}
