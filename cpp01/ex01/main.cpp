#include "Zombie.hpp"

int main()
{
	Zombie *horde = zombieHorde(-1,"Mar-1");
	
	for (int i = 0; i < -1; i++)
	{
		horde[i].announce();
	}
	delete []horde;
	return (0);
}