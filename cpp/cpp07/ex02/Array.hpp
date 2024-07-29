#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib> 
#include <string>
#include <stdexcept>


template <typename T>
class Array
{
    private:
        T   *array;
        unsigned int _size;
    public:
        Array(): array(NULL), _size(0){}
        Array(unsigned int n): array(new T[n]()), _size(n){}
        Array(const Array &o): array(new T[o._size]), _size(o._size){
            for(unsigned int i = 0; i < o._size; i++){
                array[i] = o.array[i];
			}
        }
		Array &operator=(Array &o){
			if (o != this)
			{
				delete[] array;
				_size = o._size;
				array = new T[_size];
				for(unsigned int i = 0; i < o._size; i++){
					array[i] = o.array[i];
				}
			}
			return (*this);
		}
		T	&operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::out_of_range("index is out of bounds");
			return array[i];
		} 
        ~Array(){
			delete[] array;
		}
        unsigned int	size() const{
			return (_size);
		}
};

#endif