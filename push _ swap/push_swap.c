/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docentennm <docentennm@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:06:42 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/22 21:29:34 by docentennm       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    check_arg(int argc, char *argv[], t_vr *p)
{
    if (argc < 2)
        exit(0);
    check_numbers(argv, p);
    is_daplicate(p);
    is_sorted(p);
    //max_min(p);
}

void    test(void)
{
    write(1, "Why i'm here\n", 14);
        exit(0);
}

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_vr    *p;

    stack_b = NULL;
    stack_a = NULL;
    p = (t_vr *)malloc(sizeof(t_vr));
    if (!p)
        return(0);
    check_arg(argc, argv, p);
    push_to_stack_a(&stack_a, p);
    if (argc < 5)
        sort_two_three(&stack_a);
    if (argc == 5)
        sort_four(&stack_a, &stack_b, p);
    if (argc == 6)
        sort_five(&stack_a, &stack_b, p);
    while (stack_a != NULL)
    {
        printf("--%d\n", stack_a->data);
        stack_a = stack_a->next;
    }
    
    return (0);
}