#include "HumanB.hpp"

HumanB::HumanB(std::string Name) : weapon(NULL)
{
	name = Name;
}

HumanB::~HumanB()
{

}

void    HumanB::attack()
{
	if (!weapon)
		std::cout << name << " attacks with their " << "Fist" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
