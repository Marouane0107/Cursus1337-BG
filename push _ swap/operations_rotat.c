/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docentennm <docentennm@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:41:19 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/21 04:19:32 by docentennm       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotat_a(t_stack **stack_a)
{
    t_stack *head;
    t_stack *tmp2;

    if (!(*stack_a))
        return;
    head = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    tmp2 = (*stack_a);
    while (tmp2->next != NULL)
        tmp2 = tmp2->next;
    tmp2->next = head;
    head->next = NULL;
    write(1, "ra\n", 3);
}

void    rotat_b(t_stack **stack_b)
{
    t_stack *head;
    t_stack *tmp2;

    if (!(*stack_b))
        return;
    head = (*stack_b);
    (*stack_b) = (*stack_b)->next;
    tmp2 = (*stack_b);
    while (tmp2->next != NULL)
        tmp2 = tmp2->next;
    tmp2->next = head;
    head->next = NULL;
    write(1, "rb\n", 3);
}

void    rotat_ab(t_stack **stack_a, t_stack **stack_b)
{
    if (!((*stack_a) || (*stack_b)))
        return;
    rotat_a(stack_a);
    rotat_b(stack_b);
    write(1, "rr\n", 3);
}
