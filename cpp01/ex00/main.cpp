#include "Zombie.hpp"

int	main()
{
	Zombie *Zombie;

	Zombie = newZombie("Mar-1");
	Zombie->announce();
	randomChump("Foo");

	delete(Zombie);
	return (0);
}