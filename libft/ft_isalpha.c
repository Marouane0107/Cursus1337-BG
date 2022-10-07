/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:15:46 by maouzal           #+#    #+#             */
/*   Updated: 2022/10/06 13:29:02 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int	alpha)
{
	if ((alpha >= 'A' && alpha <= 'Z') || (alpha >= 'a' && alpha <= 'z'))
		return (1);
	else
		return (0);
}
