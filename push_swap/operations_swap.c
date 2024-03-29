/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:39:47 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/17 05:27:25 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int	tmp;

	if (!(stack_a) || !(stack_a->next))
		return ;
	tmp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b)
{
	int	tmp;

	if (!(stack_b) || !(stack_b->next))
		return ;
	tmp = stack_b->data;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = tmp;
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;
	int	tmp2;

	if (!(stack_a) || !(stack_a->next) || !(stack_b) || !(stack_b->next))
		return ;
	tmp = stack_a->data;
	tmp2 = stack_b->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = tmp;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = tmp2;
	write(1, "ss\n", 3);
}
