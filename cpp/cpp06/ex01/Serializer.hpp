#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>

struct Data{
	int			num;
	std::string	str;
};

class Serializer{
	private:
		Serializer();
		Serializer(Serializer const &o);
	public:
		~Serializer();
		Serializer &operator=(Serializer const &o);
		static	uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
};

#endif