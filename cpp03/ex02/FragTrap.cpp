#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) 
{
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
	std::cout << "FragTrap "<< Name << " is created!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< Name << " is destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Give me high fives, guys!" << std::endl;
}


