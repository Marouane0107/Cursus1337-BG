#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>


class Span
{
	private:
		std::vector <unsigned int>    Numbers;
	public:
		Span();
		Span(unsigned int N);
		void	addNumber();
};


#endif