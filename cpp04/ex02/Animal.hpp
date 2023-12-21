#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class A_Animal
{
	protected:
		std::string	type;

	public:
		A_Animal();
		virtual	~A_Animal();
		virtual void	makeSound() const = 0;
		std::string		getType() const;

};

#endif
