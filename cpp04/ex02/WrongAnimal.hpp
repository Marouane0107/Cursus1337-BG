#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:

		std::string type;
	public:

		WrongAnimal();
		~WrongAnimal();
		virtual void	makeSound() const;
};


#endif
