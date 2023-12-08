
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
		void	setType(std::string Type){type = Type;}
		const std::string	&getType(void) const{return (type);}
};




#endif
