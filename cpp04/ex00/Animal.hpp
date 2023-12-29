#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& o);
		Animal& operator=(const Animal& o);
		virtual	~Animal();
		virtual void	makeSound() const;
		std::string		getType() const;

};

#endif
