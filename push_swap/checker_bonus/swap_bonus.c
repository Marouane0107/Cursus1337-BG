/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:26:49 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/17 07:16:45 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a(t_stack *stack_a)
{
	int	tmp;

	if (!(stack_a) || !(stack_a->next))
		return ;
	tmp = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = tmp;
}

void	swap_b(t_stack *stack_b)
{
	int	tmp;

	if (!(stack_b) || !(stack_b->next))
		return ;
	tmp = stack_b->data;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = tmp;
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
}
