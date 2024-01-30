#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called " << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& o)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = o;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& o)
{
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	if (this != &o)
	{
		this->type = o.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called " << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound !" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return(this->type);
}
