#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): Hit_points(10), Energy_points(10), Attack_damage(0)
{
    Name = name;
}

ClapTrap::~ClapTrap()
{
}

// void ClapTrap::attack(const std::string& target)
// {
//     std::cout<< "ClapTrap <name> attacks <target>, causing "<<  <<" points of damage!" << std::endl;
// }
