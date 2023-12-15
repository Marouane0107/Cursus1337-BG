#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called "<<std::endl;
	RawBits = 0;
}

Fixed::Fixed(const Fixed &o)
{
	std::cout << "Copy constructor called "<<std::endl;
	this->RawBits = o.RawBits;
}

Fixed& Fixed::operator=(const Fixed& o)
{
	std::cout << "Copy assignment operator called "<<std::endl;
	if(this != &o)
	{
		this->RawBits = o.RawBits;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called "<<std::endl;
}

void	Fixed::setRawBits( int const raw )
{
	RawBits = raw;
}

int		Fixed::getRawBits( void ) const
{
	return (RawBits);
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called "<<std::endl;
	RawBits = i << fractional_bits;
}

Fixed::Fixed(const float i)
{
	std::cout << "Float constructor called "<<std::endl;
	float rounded_value = roundf(i * (1 << fractional_bits));
	RawBits = static_cast<int>(rounded_value);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(RawBits) / (1 << fractional_bits));
}

int	Fixed::toInt( void ) const
{
	return (RawBits >> fractional_bits);
}

std::ostream& operator<<(std::ostream os, Fixed& floating_point)
{
	os << floating_point.toFloat();
}

bool	Fixed::operator!=(const Fixed& c)
{
	if (this != &c)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& c)
{
	if (*this == c)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& c)
{
	if (*this < c)
		return (true);
	return (false);
}


bool	Fixed::operator>(const Fixed& c)
{
	if (*this > c)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& c)
{
	if (*this >= c)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& c)
{
	if (*this <= c)
		return (true);
	return (false);
}
