#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:

		int					RawBits;
		static const int	fractional_bits; 
	public:

		Fixed();
		Fixed(const Fixed &o);
		Fixed(const int i);
		Fixed(const float f);
		Fixed& operator=(const Fixed& c);
		~Fixed();
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;
		/* comparison operators: >, <, >=, <=, == and !=       */
		bool	operator!=(const Fixed& c);
		bool	operator==(const Fixed& c);
		bool	operator<(const Fixed& c);
		bool	operator>(const Fixed& c);
		bool	operator<=(const Fixed& c);
		bool	operator>=(const Fixed& c);

		/*  arithmetic operators: +, -, *, and /          */
};
std::ostream& operator<<(std::ostream os, Fixed& floating_point);

#endif
