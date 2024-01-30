#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& o)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = o;
}

Cat& Cat::operator=(const Cat& o)
{
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &o)
	{
		this->type = o.type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
	std::cout << "Meow! Meow! Meow! "<< std::endl;
}
