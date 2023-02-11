/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:22:06 by maouzal           #+#    #+#             */
/*   Updated: 2022/11/17 23:33:13 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

unsigned int	ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
int				ft_chr(char *s);
char			*ft_strdup(const char *s1);
char			*read_line(int fd, char *str);
char			*end_line(char *str);
char			*rest_val(char *str);
char			*get_next_line(int fd);

#endif