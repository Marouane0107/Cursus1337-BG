#ifndef SCAVETRAP_H
# define SCAVETRAP_H



#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

		std::string	name;
	public:

		ScavTrap();
		ScavTrap(std::string _Name);
		ScavTrap(const ScavTrap& o);
		ScavTrap& operator =(const ScavTrap& o);
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
};







#endif
