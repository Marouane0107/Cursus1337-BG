/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:06:24 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/16 04:53:19 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_mid(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
	int	i;
	int	start;
	int	end;
	int	mid;

	i = 1;
	p->arr = sorted_array(stack_a, p);
	p->chunk_size = (ft_stack_len(stack_a) / 5);
	while (i <= 5)
	{
		start = (i - 1) * p->chunk_size;
		end = i * p->chunk_size;
		if (i == 5)
			end = p->len;
		mid = (start + end) / 2;
		p->max_chunk = p->arr[end - 1];
		p->mid_chunk = p->arr[mid];
		push_to_b(stack_a, stack_b, p);
		i++;
	}
	free(p->arr);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
	int	a;
	int	i;
	int	size;

	size = ft_stack_len(stack_a);
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->data <= p->max_chunk)
		{
			a = (*stack_a)->data;
			push_b(stack_a, stack_b);
			if (a > p->mid_chunk)
				rotat_b(stack_b);
		}
		else
			rotat_a(stack_a);
		i++;
	}
}

void	check_max_mid_500(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
	int	i;
	int	start;
	int	end;
	int	mid;

	i = 1;
	p->arr = sorted_array(stack_a, p);
	p->chunk_size = (ft_stack_len(stack_a) / 8);
	while (i <= 8)
	{
		start = (i - 1) * p->chunk_size;
		end = i * p->chunk_size;
		if (i == 8)
			end = p->len;
		mid = (start + end) / 2;
		p->max_chunk = p->arr[end - 1];
		p->mid_chunk = p->arr[mid];
		push_to_b(stack_a, stack_b, p);
		i++;
	}
	free(p->arr);
}

void	sort_100(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
	check_max_mid(stack_a, stack_b, p);
	b_to_a(stack_a, stack_b);
}

void	sort_500(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
	check_max_mid_500(stack_a, stack_b, p);
	b_to_a(stack_a, stack_b);
}
