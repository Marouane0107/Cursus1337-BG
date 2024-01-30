#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& o)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = o;
}

Brain& Brain::operator=(const Brain& o)
{
	std::cout << "Brain copy assignment called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = o.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setideas(int i, std::string	idea)
{
	if (i < 0 || i >= 100)
	{
		std::cout<< "Error out of range! " <<std::endl;
		std::exit(1);
	}
	this->ideas[i] = idea;
}

std::string Brain::getideas(int i) const
{
	if (i < 0 || i >= 100)
	{
		std::cout<< "Error out of range! " <<std::endl;
		std::exit(1);
	}
	return (ideas[i]);
}
