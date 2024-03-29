/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:37:02 by otamrani          #+#    #+#             */
/*   Updated: 2023/09/02 17:18:33 by otamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*p;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	p = malloc(sizeof(char) * len + 1);
	if (p == 0)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	ft_lstadd(&g_lobal.hold, lst_new(0, (char *)s1, p));
	return (p);
}
