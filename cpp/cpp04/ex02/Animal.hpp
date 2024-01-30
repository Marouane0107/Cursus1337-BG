#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class A_Animal
{
	protected:
		std::string	type;

	public:
		A_Animal();
		A_Animal(const A_Animal& o);
		A_Animal& operator=(const A_Animal& o);
		virtual	~A_Animal();
		virtual void	makeSound() const = 0;
		std::string		getType() const;

};

#endif
