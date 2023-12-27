#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _Name) : ClapTrap(_Name)
{
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap " << _Name << " is created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& o): ClapTrap(o)
{
	std::cout << "ScavTrap copy constructor called " << std::endl;
	*this = o;
}

ScavTrap& ScavTrap:: operator =(const ScavTrap& o)
{
	std::cout << "ScavTrap copy assignment called " << std::endl;
	if(this != &o)
	{
		this->name = o.name;
		this->Energy_points = o.Energy_points;
		this->Hit_points = o.Hit_points;
		this->Attack_damage = o.Attack_damage;
	}
	return (*this);
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
		std::cout<< "ScavTrap " << name << " attacks " << target <<", causing "<< Attack_damage <<" points of damage!" << std::endl;
		Energy_points--;
	}
	else
		std::cout << "ScavTrap " << name << " can't attack. Not enough hit points or energy points!!" << std::endl;
}
