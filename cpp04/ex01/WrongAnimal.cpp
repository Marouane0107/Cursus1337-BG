#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called " << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called " << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound !" << std::endl;
}
