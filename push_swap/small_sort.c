/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:23:02 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/13 04:48:41 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_three(t_stack **stack_a)
{
	t_stack	*tmp;
	int		a;
	int		b;
	int		c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	tmp = stack_end(*stack_a);
	c = tmp->data;
	if ((a > b && a < c) || (b == c))
		swap_a((*stack_a));
	else if (a > b && a > c && b > c)
	{
		swap_a((*stack_a));
		revrotat_a(stack_a);
	}
	else if (a > b && a > b && b < c)
		rotat_a(stack_a);
	else if (a < b && a < c && b > c)
	{
		swap_a((*stack_a));
		rotat_a(stack_a);
	}
	else if (a < b && a > c)
		revrotat_a(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
	push_b(stack_a, stack_b);
	sort_two_three(stack_a);
	git_index(stack_a, stack_b, p);
	adding_four_a(stack_a, stack_b, p);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
	push_b(stack_a, stack_b);
	sort_four(stack_a, stack_b, p);
	git_index(stack_a, stack_b, p);
	adding_five_a(stack_a, stack_b, p);
}
