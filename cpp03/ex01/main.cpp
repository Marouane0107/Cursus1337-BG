#include "ScavTrap.hpp"

int main()
{

	ClapTrap claptrap("CL4P-TP");
	claptrap.attack("Enemy1");


	ScavTrap scavtrap("SCV-TP");
	scavtrap.attack("Enemy2");
	scavtrap.takeDamage(50);
	scavtrap.guardGate();

	return 0;
}