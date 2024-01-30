
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>


class Weapon
{
	private:

		std::string type;
	public:

		Weapon(std::string	type);
		~Weapon();
		void	setType(std::string Type);
		const std::string	&getType(void) const;
};




#endif
