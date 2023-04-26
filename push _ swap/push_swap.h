/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:25:53 by maouzal           #+#    #+#             */
/*   Updated: 2023/04/26 01:52:09 by maouzal          ###   ########.fr       */
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
	int	min_1;
	int	min_2;
	int min1_pos;
	int	min2_pos;
	int	i;
	int	len;
	int	flag;
	int operation;

}           t_vr;

t_stack	*stack_end(t_stack *head);
t_stack	*new_node(int data);
void    add_back(t_stack **head, t_stack *new);
void    add_front(t_stack *head, int data);
void    ft_Error(void);
void    ft_free(char **str);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
long	ft_atoi(const char	*str);
void    check_arg(int argc, char *argv[], t_vr *p);
void    check_numbers(char *argv[], t_vr *p);
void    is_daplicate(t_vr *p);
void    is_digit(char *str);
void    check_int(char  *str);
void    check_sign(char	*str);
void    is_sorted(t_vr  *p);
void    push_to_stack_a(int argc, t_stack **stack_a, t_vr *p);
void    erray_alloction(char *argv[], t_vr *p);
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
void    sort_array(t_vr *p);
void	git_pos(t_vr *p);
void	two_min(t_vr *p);
void	check_min(t_stack **stack_a, t_stack **stack_b, t_vr *p);
void	push_min_b(t_stack **stack_a, t_stack **stack_b, t_vr *p, int pos);
int		check_pos(t_vr *p);
//void    sort_100(t_stack **stack_a, t_stack **stack_b, t_vr *p);

#endif