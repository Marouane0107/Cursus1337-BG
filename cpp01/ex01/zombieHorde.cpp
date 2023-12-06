#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N < 1)
    {
        std::cout << " Couldn't create Horde of zombies :( " << std::endl;
        return (NULL);
    }
    Zombie *Horde = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        Horde[i].setname(name);
    }
    return (Horde);
}