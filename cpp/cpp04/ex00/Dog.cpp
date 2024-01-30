#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& o)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = o;
}

Dog& Dog::operator=(const Dog& o)
{
	std::cout << "Dog copy assignment called" << std::endl;
	if (this != &o)
	{
		this->type = o.type;
	}
	return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Woof! Woof! Woof! "<< std::endl;
}
