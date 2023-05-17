/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:12:32 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/17 07:02:07 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*new_node(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	add_front(t_stack *head, int data)
{
	t_stack	*new;

	new = new_node(data);
	if (!new)
		return ;
	new->next = head;
	head = new;
}

t_stack	*stack_end(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	add_back(t_stack **head, t_stack *new)
{
	t_stack	*temp;

	if (head && new)
	{
		if (!*head)
		{
			*head = new;
			return ;
		}
		temp = stack_end(*head);
		temp->next = new;
	}
}
