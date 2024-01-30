#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout<< "FragTrap default constructor called " <<std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) 
{
	this->name = name;
	Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
	std::cout << "FragTrap "<< Name << " is created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& o)
{
	std::cout << "FragTrap copy constructor called " << std::endl;
	*this = o;
}

FragTrap& FragTrap::operator=(const FragTrap& o)
{
	std::cout << "FragTrap copy assignment called " << std::endl;
	if (this != &o)
	{
		this->name = o.name;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< Name << " is destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Give me high fives, guys!" << std::endl;
}


