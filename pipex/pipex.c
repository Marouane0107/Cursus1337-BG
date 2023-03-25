/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:41:12 by maouzal           #+#    #+#             */
/*   Updated: 2023/03/25 08:13:54 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int fd[], pid_t id, int *status)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(id, status, 0);
	wait(NULL);
}

void	ft_fork(pid_t *id)
{
	*id = fork();
	if (*id == -1)
	{
		perror("fork");
		exit(1);
	}
}

void	child1(int fd[2], t_data *p, char *av[])
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (!infile)
	{
		perror("infile error");
		exit(1);
	}
	if (dup2(infile, 0) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (dup2(fd[1], 1) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(fd[0]);
	close(infile);
	cmd_check(av[2], p, p->cmd1);
	cmd_path(p, p->cmd1);
}

void	child2(int fd[2], t_data *p, char *av[])
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!outfile)
	{
		perror("outfile error");
		exit(1);
	}
	if (dup2(outfile, 1) == -1)
	{
		perror("dup2");
		exit(1);
	}
	if (dup2(fd[0], 0) == -1)
	{
		perror("dup2");
		exit(1);
	}
	close(fd[1]);
	close(outfile);
	cmd_check(av[3], p, p->cmd2);
	cmd_path(p, p->cmd2);
}

int	main(int ac, char *av[], char *env[])
{
	int		fd[2];
	t_data	*p;
	pid_t	id;
	int		status;

	p = malloc(sizeof(t_data));
	if (!p)
		return (1);
	arg_check(ac);
	p->env = env;
	path(p, av);
	if (pipe(fd) == -1)
		return (1);
	ft_fork(&id);
	if (id == 0)
		child1(fd, p, av);
	ft_fork(&id);
	if (id == 0)
		child2(fd, p, av);
	ft_close(fd, id, &status);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
