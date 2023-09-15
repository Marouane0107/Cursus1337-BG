/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 09:36:19 by maouzal           #+#    #+#             */
/*   Updated: 2023/09/15 00:10:58 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini/minishell.h"

void	unset_head(t_data *data, t_env *tmp)
{
	if (tmp && ft_strcmp(tmp->name, data->cmd[1]) == 0)
	{
		g_lobal.env = tmp->next;
		tmp = g_lobal.env;
	}
}

void	ft_unset(t_data *data)
{
	int		i;
	t_env	*tmp;
	t_env	*tmp2;

	i = 1;
	tmp = g_lobal.env;
	unset_head(data, tmp);
	while (tmp && tmp->next && data->cmd[i])
	{
		if (ft_strcmp((tmp)->next->name, data->cmd[i]) == 0)
		{
			tmp2 = (tmp)->next;
			tmp->next = (tmp)->next->next;
			free(tmp2);
			i++;
			tmp = g_lobal.env;
		}
		tmp = (tmp)->next;
		if (!tmp && data->cmd[i])
		{
			tmp = g_lobal.env;
			i++;
		}
	}
}
