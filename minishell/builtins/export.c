/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:41:30 by maouzal           #+#    #+#             */
/*   Updated: 2023/08/25 00:30:27 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini/minishell.h"

void ft_add_env(t_data *data, char *s)
{
	char	*name;
	char	*value;
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (s[i] && s[i] != '=')
		i++;
	name = ft_substr(s, 0, i);
	if (s[i] == '=')
	{
		i++;
		f = 1;
	}
	value = ft_substr(s, i, ft_strlen(s));
	if (f == 1)
	{
		ft_setenv(&data, name, value);
		return ;
	}
	ft_lstdadd_back1(&data->env, ft_lstnew1(name, value));
}

void	ft_export(t_data *data)
{
	t_env	*tmp;
	int		i;

	i = 1;
	tmp = data->env;
	if (data->cmd[1] && data->cmd[1][0] == '=')
	{
		printf("minishell: export: `%s': not a valid identifier\n", data->cmd[1]);
		return ;
	}
	if (!data->cmd[1])
	{
		while (tmp)
		{
			printf("declare -x %s=\"%s\"\n", tmp->name, tmp->value);
			tmp = tmp->next;
		}
	}
	else
	{
		while (data->cmd[i])
			ft_add_env(data, data->cmd[i++]);
	}
}
