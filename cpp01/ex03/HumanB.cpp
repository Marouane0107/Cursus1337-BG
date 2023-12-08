#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{

}

void    HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}