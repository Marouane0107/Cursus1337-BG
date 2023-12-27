#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:

		std::string	name;
	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& o);
		FragTrap& operator=(const FragTrap& o);
		~FragTrap();
		void	highFivesGuys(void);
};



#endif
