#include "Zombie.hpp"

Zombie::Zombie(std::string Name)
{
    name = Name;
}

void	Zombie::announce()
{
    std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie "<< name << " has been destroyed" << std::endl;
}
