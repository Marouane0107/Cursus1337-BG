/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:48:24 by maouzal           #+#    #+#             */
/*   Updated: 2024/01/30 06:22:48 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(255);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	is_sorted(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
	if (!(*a))
		return ;
	tmp = (*a);
	while (tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			break ;
	}
	if (tmp->next == NULL)
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		exit(0);
	}
}

void	erray_alloction(char *argv[], t_vr *p)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	p->holder = (int *)malloc(sizeof(int) * i);
	if (!p->holder)
		return ;
}
