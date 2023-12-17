#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>
#include <string>


class ClapTrap
{
	protected:

		std::string		Name;
		unsigned int	Hit_points;
		unsigned int	Energy_points;
		unsigned int	Attack_damage;

	public:

		ClapTrap(std::string Name);
		~ClapTrap();
		void	attack(const std::string& target);
		void			beRepaired(unsigned int amount);
		void			takeDamage(unsigned int amount);

};


#endif
