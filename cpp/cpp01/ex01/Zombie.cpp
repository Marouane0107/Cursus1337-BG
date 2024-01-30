#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie "<< name << " has been destroyed" << std::endl;
}
void    Zombie::setname(std::string Name) 
{
	name = Name;
}
