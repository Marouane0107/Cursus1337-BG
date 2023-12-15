#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

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

Fixed::Fixed(const int i) 
{
	std::cout << "Int constructor called "<<std::endl;
	fixed = i << fractional_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called "<<std::endl;
	float rounded_value = roundf(f * (1 << (fractional_bits)));
	int i = static_cast<int>(rounded_value);
	fixed = i;
}

Fixed &Fixed:: operator=(const Fixed& c)
{
	std::cout << "Copy assignment operator called "<<std::endl;
	if(this != &c)
	{
		fixed = c.fixed;
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
	return (fixed);
}

float Fixed::toFloat( void ) const
{
    float float_value = static_cast<float>(fixed) / (1 << fractional_bits);
	return (float_value);
}

int Fixed::toInt( void ) const
{
	int integer = fixed >> fractional_bits;
	return (integer);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point)
{
	os << fixed_point.toFloat();
	return (os);
}
