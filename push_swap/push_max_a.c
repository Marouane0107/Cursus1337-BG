/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_max_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:38:08 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/16 10:50:41 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_tf1(t_stack **a, t_stack **b, int *down)
{
	while (get_index2(b))
	{
		if ((*down) == 0 || last_a(a) < (*b)->data)
		{
			push_a(a, b);
			rotat_a(a);
			(*down)++;
		}
		else
			revrotat_b(b);
	}
}

void	ft_tf2(t_stack **a, t_stack **b, int *down)
{
	while (get_index2(b))
	{
		if ((*down) == 0 || last_a(a) < (*b)->data)
		{
			push_a(a, b);
			rotat_a(a);
			(*down)++;
		}
		else
			rotat_b(b);
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	int	down;
	int	mid;

	down = 0;
	while ((*b))
	{
		mid = ft_stack_len(b) / 2;
		if (get_index2(b) > mid)
			ft_tf1(a, b, &down);
		else
			ft_tf2(a, b, &down);
		push_a(a, b);
		while (down != 0 && last_a(a) > get_max(b))
		{
			revrotat_a(a);
			down--;
		}
	}
	while (down != 0 && last_a(a) < get_max(b))
	{
		revrotat_a(a);
		down--;
	}
}
