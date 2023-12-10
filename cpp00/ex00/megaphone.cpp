/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maouzal <maouzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:28:16 by maouzal           #+#    #+#             */
/*   Updated: 2023/12/10 21:22:25 by maouzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char *av[])
{
	int	i = 1;
	int	j = 0;
	
	if (ac == 1)
	{
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (av[i] && av[i][j])
	{
		j = 0;
		while (av[i][j])
		{
			std::cout << (char)toupper(av[i][j++]) ;
		}
		i++;
	}
	std::cout << std::endl;
	return 0;
}