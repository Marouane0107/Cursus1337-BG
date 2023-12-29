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
		WrongAnimal(const WrongAnimal& o);
		WrongAnimal& operator=(const WrongAnimal& o);
		~WrongAnimal();
		virtual void	makeSound() const;
};


#endif
