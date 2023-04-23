/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docentennm <docentennm@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 07:26:29 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/23 19:08:11 by docentennm       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int		data;
	struct	s_stack *next;

}			t_stack;

typedef struct s_vr
{
    char    **arg;
	int	*holder;
	int	index;
	int	max;
	int	min;
	int	len;
	int	size;

}           t_vr;

t_stack	*stack_end(t_stack *head);
t_stack	*new_node(int data);
void    add_back(t_stack **head, t_stack *new);
void    add_front(t_stack *head, int data);
void    ft_Error(void);
void    ft_free(char **str);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char	*str);
void    check_arg(int argc, char *argv[], t_vr *p);
void    check_numbers(char *argv[], t_vr *p);
void    is_daplicate(t_vr *p);
void    is_digit(char *str);
void    check_int(char  *str);
void    check_sign(char	*str);
void    is_sorted(t_vr  *p);
void    push_to_stack_a(t_stack **stack_a, t_vr *p);
void    erray_alloction(char *argv[], t_vr *p);
// void    max_min(t_vr *p);
void    swap_a(t_stack *stack_a);
void    swap_b(t_stack *stack_b);
void    swap_ab(t_stack *stak_a, t_stack *stack_b);
void    rotat_a(t_stack **stack_a);
void    rotat_b(t_stack **stack_b);
void    rotat_ab(t_stack **stack_a, t_stack **stack_b);
void    revrotat_a(t_stack **stack_a);
void    revrotat_b(t_stack **stack_b);
void    revrotat_ab(t_stack **stack_a, t_stack **stack_b);
void    push_a(t_stack **stack_a, t_stack **stack_b);
void    push_b(t_stack **stack_a, t_stack **stack_b);
void    sort_two_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b, t_vr *p);
void    sort_five(t_stack **stack_a, t_stack **stack_b, t_vr *p);
void    adding_four_a(t_stack **stack_a, t_stack **stack_b, t_vr *p);
void    adding_five_a(t_stack **stack_a, t_stack **stack_b, t_vr *p);
void    git_index(t_stack **stack_a, t_stack **stack_b, t_vr *p);
//void	test(void);

#endif