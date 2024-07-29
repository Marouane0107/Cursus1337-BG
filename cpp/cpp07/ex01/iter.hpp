#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void    iter(T *Address, size_t size, void (*fun)(T const &))
{
    for(size_t i = 0; i < size; i++)
    {
        fun(Address[i]);
    }
}

template <typename T>
void    print(T const &i)
{
    std::cout << i << std::endl;
}

#endif