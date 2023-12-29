#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain& o);
		Brain& operator=(const Brain& o);
		~Brain();
		void	setideas(int i, std::string	idea);
		std::string	getideas(int i) const;
};



#endif
