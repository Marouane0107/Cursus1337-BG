/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:50:16 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/14 20:03:27 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini/minishell.h"

void	ft_exit(t_data *data)
{
	if (data->cmd[1] && !data->cmd[2])
	{
		if (ft_isdigit(data->cmd[1][0]) == 1)
			exit(ft_atoi(data->cmd[1]));
		else
		{
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("minishell: exit: ", 1);
			ft_putstr_fd(data->cmd[1], 1);
			ft_putstr_fd(": numeric argument required\n", 1);
			exit(2);
		}
	}
	if (data->cmd[1] && data->cmd[2])
	{
		ft_putstr_fd("exit\n", 1);
		ft_putstr_fd("minishell: exit: too many arguments\n", 1);
		return ;
	}
	exit(g_lobal.ex);
}
