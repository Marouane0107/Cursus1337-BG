#include "ClapTrap.hpp"

int main() 
{
	ClapTrap claptrap("Mar-1");
	claptrap.attack("Enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(2);

	return 0;
}