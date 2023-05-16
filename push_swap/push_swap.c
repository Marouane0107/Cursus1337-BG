/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:25:43 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/16 05:10:24 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg(int argc, char *argv[], t_vr *p)
{
	if (argc < 2)
		exit(0);
	check_numbers(argv, p);
	is_daplicate(p);
	is_sorted(p);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_vr	*p;

	stack_b = NULL;
	stack_a = NULL;
	p = (t_vr *)malloc(sizeof(t_vr));
	if (!p)
		return (0);
	check_arg(argc, argv, p);
	push_to_stack_a(&stack_a, p);
	if (p->len < 4)
		sort_two_three(&stack_a);
	else if (p->len == 4)
		sort_four(&stack_a, &stack_b, p);
	else if (p->len == 5)
		sort_five(&stack_a, &stack_b, p);
	else if (p->len > 5 && p->len < 101)
		sort_100(&stack_a, &stack_b, p);
	else if (p->len > 100)
		sort_500(&stack_a, &stack_b, p);
	return (0);
}
