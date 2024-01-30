#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called "<<std::endl;
	fixed = 0;
}

Fixed::Fixed(const Fixed &c)
{
	std::cout << "Copy constructor called "<<std::endl;
	*this = c;
}

Fixed &Fixed:: operator=(const Fixed& c)
{
	std::cout << "Copy assignment operator called "<<std::endl;
	if(this != &c)
	{
		this->fixed = c.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called "<<std::endl;
}

void Fixed::setRawBits( int const raw )
{
	fixed = raw;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called "<<std::endl;
	return fixed;
}
