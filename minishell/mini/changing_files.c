/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changing_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 00:25:08 by maouzal           #+#    #+#             */
/*   Updated: 2023/08/28 02:11:34 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void    in_file(t_data *data, int fd[2])
{
	if (data->in > 0)
	{
		if (dup2(data->in, 0) == -1)
			perror("dup2");
	}
	if (dup2(fd[1], 1) == -1)
		perror("dup2");
	close(fd[0]);
	close(data->in);
}

void out_file(t_data *data, int fd[2])
{
	if (data->out > 2)
	{
		if (dup2(data->out, 1) == -1)
			perror("dup2");
	}
	if (dup2(fd[0], 0) == -1)
		perror("dup2");
	close(fd[1]);
	close(data->out);
}

void	changing_files(t_data *data, int fd[2])
{
	printf("in = %d\n", data->in);
	printf("out = %d\n", data->out);
	if (data->in > 1)
		in_file(data, fd);
	else if (data->out > 1)
		out_file(data, fd);
	else
	{
		if (data->in != -1)
		{
			close(fd[0]);
			if (dup2(fd[1], 0) == -1)
				perror("dup2");
		}
		if (data->out == 0)
		{
			close(fd[1]);
			if (dup2(fd[0], 1) == -1)
				perror("dup2");
		}
	}
	
}
