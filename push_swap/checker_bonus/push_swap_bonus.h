/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:24:48 by maouzal           #+#    #+#             */
/*   Updated: 2023/05/17 06:17:29 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;

}t_stack;

typedef struct s_vr
{
	char	**arg;
	int		*holder;
	int		*arr;
	int		len;
	int		size;

}t_vr;

t_stack			*stack_end(t_stack *head);
t_stack			*new_node(int data);
void			add_back(t_stack **head, t_stack *new);
void			add_front(t_stack *head, int data);
void			ft_error(void);
void			ft_free(char **str);
int				ft_isdigit(int c);
int				ft_strcmp(const char *x, const char *y);
char			**ft_split(char const *s, char c);
long			ft_atoi(const char *str);
int				ft_stack_len(t_stack **stack);
void			check_arg(int argc, char *argv[], t_vr *p);
void			check_numbers(char *argv[], t_vr *p);
void			is_daplicate(t_vr *p);
void			is_digit(char *str);
void			check_int(char *str);
void			check_sign(char *str);
void			is_sorted(t_stack **a);
void			push_to_stack_a(t_stack **stack_a, t_vr *p);
void			erray_alloction(char *argv[], t_vr *p);
void			swap_a(t_stack *stack_a);
void			swap_b(t_stack *stack_b);
void			swap_ab(t_stack *stack_a, t_stack *stack_b);
void			rotat_a(t_stack **stack_a);
void			rotat_b(t_stack **stack_b);
void			rotat_ab(t_stack **stack_a, t_stack **stack_b);
void			revrotat_a(t_stack **stack_a);
void			revrotat_b(t_stack **stack_b);
void			revrotat_ab(t_stack **stack_a, t_stack **stack_b);
void			push_a(t_stack **stack_a, t_stack **stack_b);
void			push_b(t_stack **stack_a, t_stack **stack_b);
unsigned int	ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
int				ft_chr(char *s);
char			*ft_strdup(const char *s1);
char			*read_line(int fd, char *str);
char			*end_line(char *str);
char			*rest_val(char *str);
char			*get_next_line(int fd);
int				operatons(t_stack **a, t_stack **b, char *line);

#endif
