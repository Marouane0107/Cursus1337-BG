/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 08:55:34 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/18 17:37:21 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    check_int(char  *str)
{
    if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
    {
        free(str);
        ft_Error();
    }
}


void    is_digit(char *str)
{
    int i;

    int d;

    i = 0;
    d = 0;
    while(str[i])
    {
        d = ft_isdigit(str[i]);
        if(str[i] != '+' && str[i] != '-' && d != 1 )
        {
            free(str);
            ft_Error();
        }
        i++;
    }
}


void    check_numbers(char *argv[], t_vr *p)
{
    int i;
    int j;

    i = 1;
    p->len = 0;
    erray_alloction(argv, p);
    while (argv[i])
    {
        j = 0;
        p->arg = ft_split(argv[i], ' ');
        if (p->arg == NULL)
            return;
        while (p->arg[j])
        {
            is_digit(p->arg[j]);
            check_sign(p->arg[j]);
            check_int(p->arg[j]);
            p->holder[p->len] = ft_atoi(p->arg[j]);
            p->len++;
            j++;
        }
        ft_free(p->arg);
        i++;
    }
}

void    check_sign(char *str)
{
    int i;
    int f;

    i = 0;
    f = 0;
    while (str[i])
    {
        if ((str[i] == '+' || str[i] == '-') && f == 0)
            f = 1;
        else if ((str[i] == '+' || str[i] == '-') && f == 1)
        {
            free(str);
            ft_Error();
        }
        i++;
    }
}

void    is_daplicate(t_vr *p)
{
    int i;
    int j;

    i = 0;
    while (i < p->len)
    {
        j = i + 1;
        while (j < p->len)
        {
            if (p->holder[i] == p->holder[j])
            {
                free(p->holder);
                ft_Error();
            }
            j++;
        }
        i++;
    }
}
