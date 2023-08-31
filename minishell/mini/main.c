/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:53:13 by otamrani          #+#    #+#             */
/*   Updated: 2023/08/31 20:30:15 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int status; 

int	main(void)
{
	char	*input;
	t_data	*data;
	t_env	*envi;
	int x;
	int y;

	envi = get_environ();
	input = NULL;
	x = dup(0);
	y = dup(1);
	while (1)
	{
		dup2(x, 0);
		dup2(y, 1);
		input = readline("minishell$ ");
		add_history(input);
		data = pparss(input, envi);
		if (data)
			ft_exec(data);
		if(!data)
			continue ;
	}
	return (0);
}
