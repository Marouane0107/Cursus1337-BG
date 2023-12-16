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
		~Fixed();
		
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		Fixed&	operator=(const Fixed& c);

		/*******Comparison operators: >, <, >=, <=, == and !=  ********/
		
		bool	operator!=(const Fixed& c);
		bool	operator==(const Fixed& c);
		bool	operator<(const Fixed& c);
		bool	operator>(const Fixed& c);
		bool	operator<=(const Fixed& c);
		bool	operator>=(const Fixed& c);

		/********Arithmetic operators: +, -, *, and /  ***********/

		Fixed	operator+(const Fixed& c);
		Fixed	operator-(const Fixed& c);
		Fixed	operator*(const Fixed& c);
		Fixed	operator/(const Fixed& c);

		/************The 4 increment/decrement *****************/

		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		/*********** max       and     min ************/

		static const Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};
std::ostream& operator<<(std::ostream& os, const Fixed& Raw);

#endif
