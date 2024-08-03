#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &container, int v) {
	typename T::iterator it = std::find(container.begin(), container.end(), v);
	if (it == container.end())
		throw std::runtime_error("Value not found");
	return (it);
}

#endif