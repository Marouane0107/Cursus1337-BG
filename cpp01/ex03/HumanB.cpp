#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

void    HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}