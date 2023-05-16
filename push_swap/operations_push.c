/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:24:51 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/14 02:28:39 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_a(t_stack **stack_a, t_vr *p)
{
	t_stack	*node;
	int		i;

	i = 0;
	while (i < p->len)
	{
		node = new_node(p->holder[i]);
		add_back(stack_a, node);
		i++;
	}
	free(p->holder);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write(1, "pb\n", 3);
}
