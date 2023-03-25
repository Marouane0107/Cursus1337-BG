/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:13:54 by maouzal           #+#    #+#             */
/*   Updated: 2023/03/25 07:58:51 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char		**path;
	char		**env;
	char		**cmd1;
	char		**cmd2;
}				t_data;

int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strjoin(char *s1, char *s2);
unsigned int	ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
void			path(t_data *p, char *av[]);
void			cmd_path(t_data *p, char **cmd);
char			*ft_strchr(const char *s, int c);
void			cmd_check(char *av, t_data *p, char **cmd);
void			arg_check(int ac);

#endif
