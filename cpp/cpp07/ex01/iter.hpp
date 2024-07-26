#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void    iter(T *address, size_t length, void (*fun)(T &))
{
	for(size_t i = 0; i < length; i++)
	{
		fun(address[i]);
	}
}

template <typename T>

void	print(T &i)
{
	std::cout << i << std::endl;
}

#endif