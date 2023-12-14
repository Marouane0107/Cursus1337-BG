#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <string>

class Fixed
{
	private:

		int					fixed;
		static const int	save = 8; 
	public:

		Fixed();
		Fixed(const Fixed &c);
		Fixed& operator=(const Fixed& c);
		~Fixed();
		void setRawBits( int const raw );
		int getRawBits( void ) const;
};

#endif

