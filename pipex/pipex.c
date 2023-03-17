/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:41:12 by maouzal           #+#    #+#             */
/*   Updated: 2023/03/17 17:02:40 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_check(int ac)
{
	if (ac != 5)
	{
		write(2, "Error invalid number of arguments!", 35);
		exit(1);
	}
}

void	child(int fd[2], t_data *p, char *av[])
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (!infile)
		perror("infile error");
	dup2(infile, 0);
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	cmd_path(p, p->cmd1);
}

void	parent(int fd[2], t_data *p, char *av[])
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!outfile)
		perror("outfile error");
	dup2(outfile, 1);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	cmd_path(p, p->cmd2);
}

int	main(int ac, char *av[], char *env[])
{
	int fd[2];
	t_data *p;
	pid_t id;

    p = malloc(sizeof(t_data));
    if (!p)
        return(0);
	arg_check(ac);
	p->env = env;
	path(p, av);
	pipe(fd);
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
		child(fd, p, av);
	else
	{
		wait(NULL);
		parent(fd, p, av);
	}

	return (0);
}