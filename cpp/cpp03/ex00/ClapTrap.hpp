#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>


class ClapTrap
{
	private:

		std::string		Name;
		unsigned int	Hit_points;
		unsigned int	Energy_points;
		unsigned int	Attack_damage;

	public:

		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap& o);
		ClapTrap& operator =(const ClapTrap& o);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};


#endif
