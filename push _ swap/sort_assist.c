/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_assist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:26:06 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/24 22:40:07 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    git_index(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
    t_stack *tmp;
    
    tmp = (*stack_a);
    p->index = 0;
    while (tmp)
    {
        if ((*stack_b)->data > tmp->data)
            p->index++;
        tmp = tmp->next;
    }
}

void    adding_four_a(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
    if (p->index == 0)
        push_a(stack_a, stack_b);
    else if (p->index == 1)
    {
        push_a(stack_a, stack_b);
        swap_a((*stack_a));
    }
    else if (p->index == 2)
    {
        push_a(stack_a, stack_b);
        revrotat_a(stack_a);
        swap_a((*stack_a));
        rotat_a(stack_a);
        rotat_a(stack_a);
    }
    else if (p->index == 3)
    {
        push_a(stack_a, stack_b);
        rotat_a(stack_a);
    }
}

void    index_two(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
    if (p->index == 2)
    {
        push_a(stack_a, stack_b);
        revrotat_a(stack_a);
        swap_a((*stack_a));
        revrotat_a(stack_a);
        swap_a((*stack_a));
        rotat_a(stack_a);
        rotat_a(stack_a);
        rotat_a(stack_a);
    }
}

void    adding_five_a(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
    if (p->index == 0)
        push_a(stack_a, stack_b);
    else if (p->index == 1)
    {
        push_a(stack_a, stack_b);
        swap_a((*stack_a));
    }
    index_two(stack_a, stack_b, p);
    if (p->index == 3)
    {
        push_a(stack_a, stack_b);
        revrotat_a(stack_a);
        swap_a((*stack_a));
        rotat_a(stack_a);
        rotat_a(stack_a);
    }
    else if (p->index == 4)
    {
        push_a(stack_a, stack_b);
        rotat_a(stack_a);
    }
}
