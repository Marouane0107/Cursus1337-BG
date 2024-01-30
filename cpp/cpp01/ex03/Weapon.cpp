#include "Weapon.hpp"

Weapon::Weapon(std::string	type)
{
    this->type = type;
}

Weapon::~Weapon()
{

}

void	Weapon::setType(std::string Type)
{
    type = Type;
}

const std::string&	Weapon::getType(void) const
{
    return (type);
}
