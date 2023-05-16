/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:25:00 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/14 01:10:11 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotat_a(t_stack **stack_a)
{
	t_stack	*new_head;
	t_stack	*tmp2;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	tmp2 = (*stack_a);
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	new_head = tmp2->next;
	tmp2->next = NULL;
	new_head->next = (*stack_a);
	(*stack_a) = new_head;
	write(1, "rra\n", 4);
}

void	revrotat_b(t_stack **stack_b)
{
	t_stack	*new_head;
	t_stack	*tmp2;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	tmp2 = (*stack_b);
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	new_head = tmp2->next;
	tmp2->next = NULL;
	new_head->next = (*stack_b);
	(*stack_b) = new_head;
	write(1, "rrb\n", 4);
}

void	revrotat_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (!((*stack_a) || (*stack_b)))
		return ;
	revrotat_a(stack_a);
	revrotat_b(stack_b);
	write(1, "rrr\n", 4);
}
