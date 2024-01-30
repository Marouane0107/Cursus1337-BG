#include "Animal.hpp"

A_Animal::A_Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal& o)
{
	std::cout << "A_Animal copy constructor called" << std::endl;
	*this = o;
}

A_Animal& A_Animal::operator=(const A_Animal& o)
{
	std::cout << "A_Animal copy assignment called" << std::endl;
	if (this != &o)
	{
		this->type = o.type;
	}
	return (*this);
}

A_Animal::~A_Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string A_Animal::getType() const
{
	return (type);
}
