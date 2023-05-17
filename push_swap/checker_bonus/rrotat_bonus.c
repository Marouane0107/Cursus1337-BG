/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:20:32 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/17 07:16:31 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	revrotat_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_head;
	t_stack	*tmp;
	t_stack	*new_head2;
	t_stack	*tmp2;

	if (!(*stack_a) || !((*stack_a)->next) || !(*stack_b)
		|| !((*stack_b)->next))
		return ;
	tmp = (*stack_a);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	new_head = tmp->next;
	tmp->next = NULL;
	new_head->next = (*stack_a);
	(*stack_a) = new_head;
	tmp2 = (*stack_b);
	while (tmp2->next->next != NULL)
		tmp2 = tmp2->next;
	new_head2 = tmp2->next;
	tmp2->next = NULL;
	new_head2->next = (*stack_b);
	(*stack_b) = new_head;
}
