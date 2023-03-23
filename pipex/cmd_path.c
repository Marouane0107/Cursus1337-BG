/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:52:04 by maouzal           #+#    #+#             */
/*   Updated: 2023/03/23 23:44:15 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path(t_data *p, char *av[])
{
	int		i;
	char	*f_path;

	i = 0;
	while (p->env[i] && ft_strncmp(p->env[i], "PATH", 4))
		i++;
	if (!p->env[i])
	{
		write(2, "command not found\n", 19);
		exit(1);
	}
	f_path = p->env[i] + 5;
	p->path = ft_split(f_path, ':');
	p->cmd1 = ft_split(av[2], ' ');
	if (!p->cmd1[0])
	{
		write(2, "permission denied:\n", 20);
		exit(127);
	}
	p->cmd2 = ft_split(av[3], ' ');
	if (!p->cmd2[0])
	{
		write(2, "permission denied:\n", 20);
		exit(127);
	}
}

void	cmd_path(t_data *p, char **cmd)
{
	int		i;
	char	*path_cmd;
	char	*cmd_part;

	i = 0;
	while (p->path[i])
	{
		cmd_part = ft_strjoin(p->path[i], "/");
		path_cmd = ft_strjoin(cmd_part, cmd[0]);
		if (access(path_cmd, X_OK) == -1)
			free(path_cmd);
		else if(execve(path_cmd, cmd, p->env) == -1)
		{
			perror("command not found");
			exit(127);
		}
		i++;
	}
	write (2 , *cmd, ft_strlen(*cmd));
	write (2, ": command not found\n", 21);
	exit(127);
}

void	cmd_check(char *av, t_data *p, char **cmd)
{
	if (av[0] == '/' || av[0] == '.')
	{
		if (access(av, X_OK) == -1)
		{
			write(2, "no such file or directory\n", 27);
			exit(1);
		}
		else if (execve(av, cmd, p->env) == -1)
		{
			perror("command not found");
			exit(127);
		}
	}
}
