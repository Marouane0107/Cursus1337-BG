/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:38:08 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/26 17:28:40 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_b(t_stack **stack_a, t_stack **stack_b, t_vr *p, int pos)
{
	int		i;

	i = 0;
    if (pos == 1)
    {
        swap_a((*stack_a));
        push_b(stack_a, stack_b);
        if (p->flag == 1)
            swap_b((*stack_b));
        return;
    }
	while (i < pos && (p->operation == 2 || p->operation == 5))
	{
        rotat_a(stack_a); 
        i++;
	}
    i = 0;
    while (i < pos && (p->operation == 3 || p->operation == 4))
    {
        revrotat_a(stack_a);
        i++;
    }
    push_b(stack_a, stack_b);
    if (p->flag == 1)
        swap_b((*stack_b));
}

void	check_min(t_stack ** stack_a, t_stack **stack_b, t_vr *p)
{
	int first;

	first = check_pos(p);
	if (first == p->min_1)
	{
        push_min_b(stack_a, stack_b, p, p->min1_pos);
	}
    else if (first == p->min_2)
    {
        push_min_b(stack_a, stack_b, p, p->min2_pos);
        if (p->operation == 4)
            p->operation = 2;
        if (p->operation == 5)
            p->operation = 3;
        p->flag = 1;
        push_min_b(stack_a, stack_b, p, p->min1_pos);
        p->i++;
    }
}
