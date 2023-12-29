#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
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
		this->brain = new Brain(*o.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void    Cat::makeSound() const
{
	std::cout << "Meow! Meow! Meow! "<< std::endl;
}

Brain* Cat::getbrain(void) const
{
	return (this->brain);
}
