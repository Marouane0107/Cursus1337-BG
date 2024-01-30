/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_get_next_line.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:22:06 by maouzal           #+#    #+#             */
/*   Updated: 2024/01/05 04:43:49 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_GET_NEXT_LINE_BONUS_H
# define M_GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char			*read_line(int fd, char *str);
char			*end_line(char *str);
char			*rest_val(char *str);
char			*m_get_next_line(int fd);

#endif
