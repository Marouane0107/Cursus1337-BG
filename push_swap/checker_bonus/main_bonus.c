/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:24:10 by maouzal           #+#    #+#             */
/*   Updated: 2024/01/30 06:21:33 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_arg(int argc, char *argv[], t_vr *p)
{
	if (argc < 2)
		exit(0);
	check_numbers(argv, p);
	is_daplicate(p);
}

int	main(int ac, char *av[])
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_vr	*p;

	stack_b = NULL;
	stack_a = NULL;
	p = (t_vr *)malloc(sizeof(t_vr));
	if (!p)
		return (0);
	check_arg(ac, av, p);
	push_to_stack_a (&stack_a, p);
	line = get_next_line(0);
	while (line)
	{
		if (operatons(&stack_a, &stack_b, line) != 0)
		{
			free(line);
			ft_error();
		}
		line = get_next_line(0);
	}
	free(line);
	is_sorted(&stack_a, &stack_b);
	return (0);
}
