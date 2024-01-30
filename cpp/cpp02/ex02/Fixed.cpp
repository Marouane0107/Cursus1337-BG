#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed()
{
	//std::cout << "Default constructor called "<<std::endl;
	RawBits = 0;
}

Fixed::Fixed(const Fixed &o)
{
	//std::cout << "Copy constructor called "<<std::endl;
	*this = o;
}


Fixed::Fixed(const int i)
{
	//std::cout << "Int constructor called "<<std::endl;
	RawBits = i << fractional_bits;
}

Fixed::Fixed(const float i)
{
	//std::cout << "Float constructor called "<<std::endl;
	float rounded_value = roundf(i * (1 << fractional_bits));
	RawBits = static_cast<int>(rounded_value);
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called "<<std::endl;
}

void	Fixed::setRawBits( int const raw )
{
	RawBits = raw;
}

int		Fixed::getRawBits( void ) const
{
	return (RawBits);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(RawBits) / (1 << fractional_bits));
}

int	Fixed::toInt( void ) const
{
	return (RawBits >> fractional_bits);
}

Fixed& Fixed::operator=(const Fixed& o)
{
	//std::cout << "Copy assignment operator called "<<std::endl;
	if(this != &o)
	{
		this->RawBits = o.RawBits;
	}
	return (*this);
}


/*******Comparison operators: >, <, >=, <=, == and !=  ********/

bool	Fixed::operator!=(const Fixed& c)
{
	if (this->RawBits != c.RawBits)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& c)
{
	if (this->RawBits == c.RawBits)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& c)
{
	if (this->RawBits < c.RawBits)
		return (true);
	return (false);
}


bool	Fixed::operator>(const Fixed& c)
{
	if (this->RawBits > c.RawBits)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& c)
{
	if (this->RawBits >= c.RawBits)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& c)
{
	if (this->RawBits <= c.RawBits)
		return (true);
	return (false);
}

/********Arithmetic operators: +, -, *, and /  ***********/

Fixed	Fixed::operator+(const Fixed& c)
{
	this->RawBits += c.RawBits;
	return (*this);
}

Fixed	Fixed::operator-(const Fixed& c)
{
	this->RawBits -= c.RawBits;
	return (*this);
}

Fixed	Fixed::operator*(const Fixed& c)
{
	this->RawBits *= c.RawBits / (1 << fractional_bits);
	return (*this);
}

Fixed	Fixed::operator/(const Fixed& c)
{
	if (c.RawBits == 0)
		return (0);
	this->RawBits /= c.RawBits / (1 << fractional_bits);
	return (*this);
}

/************The 4 increment/decrement *****************/

Fixed	Fixed::operator++()
{
	this->RawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
			++*this;
	return (tmp);
}

Fixed	Fixed::operator--()
{
	Fixed result(this->RawBits--);
	return (result);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
			--*this;
	return (tmp);
}

/*********** max       and     min ************/

const Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.RawBits < b.RawBits)
		return(a);
	return (b);
}

const Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.RawBits > b.RawBits)
		return(a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.RawBits > b.RawBits)
		return(a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.RawBits > b.RawBits)
		return(a);
	return (b);
}

/* ******* Overload of the insertion («) operator *********/

std::ostream& operator<<(std::ostream& os, const Fixed& Raw)
{
	os << Raw.toFloat();
	return os;
}

