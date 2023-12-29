#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout<< "WrongCat default constructor called "<< std::endl;
}

WrongCat::WrongCat(const WrongCat& o)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = o;
}

WrongCat& WrongCat::operator=(const WrongCat& o)
{
	std::cout << "WrongCat copy assignment called" << std::endl;
	if (this != &o)
	{
		this->type = o.type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout<< "WrongCat default destructor called "<< std::endl;
}
