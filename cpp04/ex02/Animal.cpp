#include "Animal.hpp"

A_Animal::A_Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

A_Animal::~A_Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string A_Animal::getType() const
{
	return (type);
}
