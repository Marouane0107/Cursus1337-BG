#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called " << std::endl;
}

ClapTrap::ClapTrap(std::string name): Name(name) , Hit_points(10), Energy_points(10), Attack_damage(0)
{
	std::cout << "ClapTrap constructor called " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& o)
{
	std::cout << "ClapTrap copy constructor called " << std::endl;
	*this = o;
}

ClapTrap& ClapTrap:: operator =(const ClapTrap& o)
{
	std::cout << "ClapTrap copy assignment called " << std::endl;
	if(this != &o)
	{
		this->Energy_points = o.Energy_points;
		this->Hit_points = o.Hit_points;
		this->Attack_damage = o.Attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called " << std::endl;
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
	if (Hit_points > 0 && Energy_points > 0)
	{
		Hit_points += amount;
		Energy_points--;
		std::cout << "ClapTrap " << Name << " repaired " << amount << " hit points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << Name << " can't be repaired. Not enough hit points or energy points!!" << std::endl;
}
