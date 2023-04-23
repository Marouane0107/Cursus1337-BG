/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docentennm <docentennm@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 00:25:55 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/23 20:02:49 by docentennm       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two_three(t_stack **stack_a)
{
    t_stack *tmp;
    int a;
    int b;
    int c;

    a = (*stack_a)->data;
    b = (*stack_a)->next->data;
    tmp = stack_end(*stack_a);
    c = tmp->data; 
    if ((a > b && a < c) || (b == c))
    {
        write(1,"how!!\n", 6);
        swap_a((*stack_a));
    }
    else if (a > b && a > c && b > c)
    {
        swap_a((*stack_a));
        revrotat_a(stack_a);
    }
    else if (a > b && a > b && b < c)
        rotat_a(stack_a);
    else if (a < b && a < c && b > c)
    {
        swap_a((*stack_a));
        rotat_a(stack_a);
    }
    else if (a < b && a > c)
        revrotat_a(stack_a);
}


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

void    adding_five_a(t_stack **stack_a, t_stack **stack_b, t_vr *p)
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
        revrotat_a(stack_a);
        swap_a((*stack_a));
        rotat_a(stack_a);
        rotat_a(stack_a);
        rotat_a(stack_a);
    }
    else if (p->index == 3)
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

void    sort_four(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{   
    push_b(stack_a, stack_b);
    sort_two_three(stack_a);
    git_index(stack_a, stack_b, p);
    adding_four_a(stack_a, stack_b, p);
}

void    sort_five(t_stack **stack_a, t_stack **stack_b, t_vr *p)
{
    push_b(stack_a, stack_b);
    sort_four(stack_a, stack_b, p);
    git_index(stack_a, stack_b, p);
    adding_five_a(stack_a, stack_b, p);
}