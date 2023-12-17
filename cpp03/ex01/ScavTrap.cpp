#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap " << Name << " is created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " is destroyed!" << std::endl;
}

void	ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode " << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (Hit_points > 0 && Energy_points > 0)
	{
		std::cout<< "ScavTrap " << Name << " attacks " << target <<", causing "<< Attack_damage <<" points of damage!" << std::endl;
		Energy_points--;
	}
	else
		std::cout << "ClapTrap " << Name << " can't attack. Not enough hit points or energy points!!" << std::endl;
}
