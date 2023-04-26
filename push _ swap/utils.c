/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:26:18 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/25 10:51:23 by maouzal          ###   ########.fr       */
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
