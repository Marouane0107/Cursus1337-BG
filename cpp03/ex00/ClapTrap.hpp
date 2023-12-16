#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>


class ClapTrap
{
	private:

		std::string Name;
		int			Hit_points;
		int			Energy_points;
		int			Attack_damage;

	public:

		ClapTrap(std::string Name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};


#endif
