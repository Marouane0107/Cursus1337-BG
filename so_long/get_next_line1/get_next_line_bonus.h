/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:48:59 by maouzal           #+#    #+#             */
/*   Updated: 2022/11/19 15:40:38 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

unsigned int	ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char *s1, char *s2);
int				chr(char *s);
char			*read_line(int fd, char *str);
char			*end_line(char *str);
char			*rest_val(char *str);
char			*get_next_line(int fd);

#endif