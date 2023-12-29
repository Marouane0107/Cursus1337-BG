#include "ClapTrap.hpp"

int main() 
{
	ClapTrap a("Mar-1");
	a.attack("Enemy");
	a.takeDamage(5);
	a.beRepaired(2);

	return 0;
}