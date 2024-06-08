#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iostream>
#include <string>
#include <cstdlib>
#include <stdint.h>

typedef struct Data{
	int a;
	Data():a(5){};
};

class Serializer{
	public:
		Serializer();
		~Serializer();
		Serializer(Serializer const &o);
		Serializer &operator=(Serializer const &o);
		static	uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
};

#endif