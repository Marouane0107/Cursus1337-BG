#include "HumanB.hpp"

HumanB::HumanB(std::string Name)
{
	name = Name;
}

void    HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}