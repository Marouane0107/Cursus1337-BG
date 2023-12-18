#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void    Cat::makeSound() const
{
	std::cout << "Meow! Meow! Meow! "<< std::endl;
}
