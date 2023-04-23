/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:39:47 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/18 02:30:53 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_stack *stack_a)
{
    int tmp;

    if (!(stack_a || stack_a->next))
        return;
    tmp = stack_a->data;
    stack_a->data = stack_a->next->data;
    stack_a->next->data = tmp;
    write(1, "sa\n", 3);
}

void    swap_b(t_stack *stack_b)
{
    int tmp;

    if (!(stack_b->data || stack_b))
        return;

    tmp = stack_b->data;
    stack_b->data = stack_b->next->data;
    stack_b->next->data = tmp;
    write(1, "sb\n", 3);
}

void    swap_ab(t_stack *stak_a, t_stack *stack_b)
{
    swap_a(stak_a);
    swap_b(stack_b);
    write(1, "ss\n", 3);
}
