/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 05:33:28 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/17 07:41:46 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	operatons(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap_a((*a));
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_b((*b));
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_ab((*a), (*b));
	else if (ft_strcmp(line, "pa\n") == 0)
		push_a(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_b(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotat_a(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotat_b(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotat_ab(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		revrotat_a(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		revrotat_b(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		revrotat_ab(a, b);
	else
		return (1);
	return (0);
}
