/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:41:48 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/20 04:54:18 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void    ft_Error(void)
{
    write(2, "Error\n", 7);
    exit(255);
}

void    ft_free(char **str)
{
    int i;

    i = 0;
    if (str)
    {
        while (str[i])
        {
            free(str[i]);
            i++;
        }
        free(str);
    }
}

void    is_sorted(t_vr  *p)
{
    int i;
    
    i = 0;
    while (i < p->len - 1)
    {
        if (p->holder[i] < p->holder[i + 1])
            i++;
        else
            return;
    }
    if (i + 1 == p->len)
        exit(0);
}

void    erray_alloction(char *argv[], t_vr *p)
{
    int i;

    i = 0;
    while(argv[i])
        i++;
    p->holder = (int *)malloc(sizeof(int) * i);
    if (!p->holder)
        return;
}

// void    max_min(t_vr *p, t_stack **stack_a)
// {
//     int i;

//     i = 0;
//     p->max = p->holder[0];
//     p->min = p->holder[0];
//     while (i < p->len)
//     {
//         if (p->holder[i] > p->max)
//             p->max = p->holder[i];
//         if (p->holder[i] < p->min)
//             p->min = p->holder[i];
//         i++;
//     }
// }