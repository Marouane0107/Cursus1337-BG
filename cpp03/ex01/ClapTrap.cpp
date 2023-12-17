#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): Name(name) , Hit_points(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap " << Name << " is created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (Hit_points > 0 && Energy_points > 0)
	{
		std::cout<< "ClapTrap " << Name << " attacks " << target <<", causing "<< Attack_damage <<" points of damage!" << std::endl;
		Energy_points--;
	}
	else
		std::cout << "ClapTrap " << Name << " can't attack. Not enough hit points or energy points!!" << std::endl;
}
void    ClapTrap::takeDamage(unsigned int amount)
{
	int save = amount;
	if (save < 0)
	{
		std::cout << "Damage amount can't be negative" << std::endl;
		return;
	}
	if (Hit_points > 0)
	{
		if (amount >= Hit_points)
		{
			amount = Hit_points;
			Hit_points = 0;
		}
		else
			Hit_points -= amount;
		std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << Name << " is already defeated and can't take more damage." << std::endl;
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int save = amount;
	if (save < 0)
	{
		std::cout << "Repaired amount can't be negative" << std::endl;
		return;
	}
	if (Hit_points > 0 && Energy_points > 0)
	{
		Hit_points += amount;
		Energy_points--;
		std::cout << "ClapTrap " << Name << " repaired " << amount << " hit points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << Name << " can't be repaired. Not enough hit points or energy points!!" << std::endl;
}
