/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:22:46 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/26 16:29:49 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	full_array()
// {
	
// }

void	sort_array(t_vr *p)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	while (i < p->len)
	{
		j = i + 1;
		while (j < p->len)
		{
			if (p->holder[i] < p->holder[j])
				j++;
			else
			{
				a = p->holder[i];
				p->holder[i] = p->holder[j];
				p->holder[j] = a;
				j++;
			}
		}
		i++;
	}
}

void	git_pos(t_vr *p)
{
	int i;
	int size;
	
	i = 0;
	size = p->len;
	while (i < size)
	{
		if (p->holder[i] == p->min_1)
			p->min1_pos = i;
		if (p->holder[i] == p->min_2)
			p->min2_pos = i;
		i++;
	}
}

void	two_min(t_vr *p)
{
	int size;

	size = p->len;
	sort_array(p);
	if (p->i < size)
	{
		p->min_1 = p->holder[p->i];
		p->min_2 = p->holder[p->i + 1];
		git_pos(p);
		p->i++;
	}
}

int	check_pos2(t_vr *p, int mid, int first, int rest)
{
	if (p->min1_pos < mid && p->min2_pos > mid)
	{
		rest = p->min2_pos - p->len;
		if (p->min1_pos <= rest)
		{
			first = p->min_1;
			p->operation = 2;
			return (first);
		}
		else
		{
			first = p->min_2;
			p->operation = 4;
			return (first);
		}
	}
	else if (p->min1_pos > mid && p->min2_pos < mid)
	{
		rest = p->min1_pos - p->len;
		if (p->min2_pos <= rest)
		{
			first = p->min_2;
			p->operation = 5;
			return (first);
		}
		else
		{
			first = p->min_1;
			p->operation = 2;
			return (first);
		}
	}
	return (first);
}

int	check_pos(t_vr *p)
{
	int mid;
	int	first;
	int	rest;

	first = 0;
	rest = 0;
	mid = p->len / 2;
	two_min(p);
	if (p->min1_pos < mid && p->min2_pos < mid)
	{
		p->operation = 2;
		if (p->min1_pos < p->min2_pos)
		{
			first = p->min_1;
			return (first);
		}
		else
		{
			first = p->min_2;
			return (first);
		}
	}
	else if (p->min1_pos > mid && p->min2_pos > mid)
	{
		p->operation = 3;
		if (p->min1_pos > p->min2_pos)
		{
			first = p->min_1;
			return (first);
		}
		else
		{
			first = p->min_2;
			return (first);
		}
	}
	else
	{
		first = check_pos2(p, mid, first, rest);
		return (first);
	}
	return (first);
}
