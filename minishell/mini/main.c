/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:53:13 by otamrani          #+#    #+#             */
/*   Updated: 2023/09/15 01:41:01 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_lobal;

int	main(void)
{
	g_lobal.i = 1;
	g_lobal.j = 0;
	g_lobal.e = 0;
	parss();
	return (0);
}
