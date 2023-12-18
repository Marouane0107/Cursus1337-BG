#ifndef SCAVETRAP_H
# define SCAVETRAP_H



#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:

		ScavTrap(std::string Name);
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
};







#endif
