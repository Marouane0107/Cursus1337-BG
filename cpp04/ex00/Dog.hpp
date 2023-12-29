#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& o);
		Dog& operator=(const Dog& o);
		~Dog();
		void	makeSound() const;
};



#endif
