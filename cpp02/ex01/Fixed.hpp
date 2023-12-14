#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:

		int					fixed;
		static const int	fractional_bits; 
	public:

		Fixed();
		Fixed(const Fixed &c);
        Fixed(const int i);
        Fixed(const float f);
		Fixed& operator=(const Fixed& c);
		~Fixed();
		void setRawBits( int const raw );
		int getRawBits( void ) const;
        float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point);

#endif
