#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
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
		this->brain = new Brain(*o.brain);
	}
	return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void    Dog::makeSound() const
{
    std::cout << "Woof! Woof! Woof! "<< std::endl;
}

Brain* Dog::getbrain(void) const
{
	return (this->brain);
}
