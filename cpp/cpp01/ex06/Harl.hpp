#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>


class Harl
{
	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	invalid(void);
	public:

		void	complain( std::string level );
		int		get_lvl(std::string level);
};


#endif
