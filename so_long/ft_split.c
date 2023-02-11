/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:28:09 by maouzal           #+#    #+#             */
/*   Updated: 2023/02/08 22:21:00 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count(char const *s, char c)
{
	int	x;
	int	i;
	int	count;

	i = 0;
	x = 0;
	count = 0;
	while (s[x] != '\0')
	{
		if (s[x] != c && i == 0)
		{
			count++;
			i = 1;
		}
		else if (s[x] == c)
			i = 0;
		x++;
	}
	return (count);
}

static void	ft_size0(const char *s, char c, int w, int *p)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	i = 0;
	j = 0;
	while (s[x] != '\0')
	{
		if (s[x] != c)
		{
			w++;
			j = 1;
		}
		else if (s[x] == c && j == 1)
		{
			p[i] = w + 1;
			i++;
			w = 0;
			j = 0;
		}
		x++;
	}
	if (x && s[x - 1] != c)
		p[i] = w + 1;
}

static int	*ft_size(char const *s, char c, unsigned int count)
{
	int	w;
	int	*p;

	w = 0;
	p = malloc(count * sizeof(int));
	if (!(p))
		return (0);
	ft_size0(s, c, w, p);
	return (p);
}

static void	ft_spl(const char *s, char c, char **ns)
{
	int	i;
	int	j;
	int	w;
	int	count;

	w = 0;
	i = 0;
	j = 0;
	while (s[w] != '\0')
	{
		if (s[w] != c)
		{
			ns[i][j++] = s[w];
			count = 1;
		}
		else if (s[w] == c && count == 1)
		{
			ns[i++][j] = '\0';
			j = 0;
			count = 0;
		}
		w++;
	}
	if (w && s[w - 1] != c)
		ns[i][j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	int		*p;
	char	**ns;

	if (!s)
		return (0);
	count = ft_count(s, c);
	p = ft_size(s, c, count);
	i = 0;
	ns = malloc((count + 1) * sizeof(char *));
	if (!(ns))
		return (0);
	while (i < count)
	{
		ns[i] = malloc((p[i]) * sizeof(char));
		if (!(ns[i++]))
			return (0);
	}
	free(p);
	ns[i] = 0;
	i = 0;
	count = 0;
	ft_spl(s, c, ns);
	return (ns);
}
