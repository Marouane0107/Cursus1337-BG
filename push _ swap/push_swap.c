/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:25:43 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/26 18:50:08 by maouzal          ###   ########.fr       */
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
    // max_min(p);
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
    push_to_stack_a(argc, &stack_a, p);
    if (argc < 5)
        sort_two_three(&stack_a);
    if (argc == 5)
        sort_four(&stack_a, &stack_b, p);
    if (argc == 6)
        sort_five(&stack_a, &stack_b, p);
    if (argc > 6)
    {
        p->flag = 0;
        p->i = 0;
        sort_array(p);
        while (stack_a)
        {
            check_min(&stack_a, &stack_b, p);
            if (p->len >= 0)
                p->len--;
        }
    }
    
    return (0);
}
    // int j;
 
    // j = 0;
    // while (stack_b)
    // {
    //     printf ("-----%d\n", stack_b->data);
    //     stack_b = stack_b->next;
    //     j++;
    // }
    // printf("%d",j);