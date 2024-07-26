#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "iostream"
#include "string"
#include "exception"

template <typename T>

class Array
{
	private:
		T	*data;
		unsigned int n;
	public:
		Array() : data(NULL), n(0) {}
		Array(unsigned int n) : data(new T[n]), n(n) {}
		Array(const Array &other) : data(new T[other.n]), n(other.n)
		{
			for (unsigned int i = 0; i < n; i++)
				data[i] = other.data[i];
		}
		~Array()
		{
			delete[] data;
		}
		Array &operator=(const Array &other)
		{
			if (this == &other)
				return *this;
			delete[] data;
			data = new T[other.n];
			n = other.n;
			for (unsigned int i = 0; i < n; i++)
				data[i] = other.data[i];
			return *this;
		}
		T &operator[](unsigned int i)
		{
			if (i >= n)
				throw std::exception();
			return data[i];
		}
		unsigned int size() const
		{
			return n;
		}
};

#endif