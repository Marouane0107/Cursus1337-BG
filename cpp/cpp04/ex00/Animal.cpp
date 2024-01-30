#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& o)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = o;
}

Animal& Animal::operator=(const Animal& o)
{
	std::cout << "Animal copy assignment called" << std::endl;
	if (this != &o)
	{
		this->type = o.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Unknown Animal sound !" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
