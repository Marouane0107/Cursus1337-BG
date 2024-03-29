/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:25:09 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/17 05:24:08 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotat_a(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*tmp2;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	head = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp2 = (*stack_a);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = head;
	head->next = NULL;
	write(1, "ra\n", 3);
}

void	rotat_b(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*tmp2;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	head = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp2 = (*stack_b);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = head;
	head->next = NULL;
	write(1, "rb\n", 3);
}

void	rotat_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*tmp;
	t_stack	*head2;
	t_stack	*tmp2;

	if (!(*stack_a) || !((*stack_a)->next) || !(*stack_b)
		|| !((*stack_b)->next))
		return ;
	head = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp = (*stack_a);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = head;
	head->next = NULL;
	head2 = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp2 = (*stack_b);
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = head2;
	head2->next = NULL;
	write(1, "rr\n", 3);
}
