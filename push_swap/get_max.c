/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:22:46 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/16 10:34:58 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_len(t_stack **stack)
{
	t_stack	*tmp;
	int		len;

	tmp = (*stack);
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	last_a(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (!(*a))
		return (0);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp->data);
}

void	indexing(t_stack *b)
{
	int	i;

	if (!b)
		return ;
	i = 0;
	while (b)
	{
		b->index = i;
		i++;
		b = b->next;
	}
}

int	get_max(t_stack **stack_b)
{
	int		max;
	t_stack	*tmp;

	if (!(*stack_b))
		return (0);
	max = (*stack_b)->data;
	tmp = (*stack_b);
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	get_index2(t_stack **stack_b)
{
	t_stack	*tmp;
	int		max;

	indexing((*stack_b));
	max = get_max(stack_b);
	if (!(*stack_b))
		return (0);
	tmp = (*stack_b);
	while (tmp)
	{
		if (tmp->data == max)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (tmp->index);
}
