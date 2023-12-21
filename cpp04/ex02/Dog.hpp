#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public A_Animal
{
	private:

		Brain *brain;
	public:
		Dog();
		~Dog();
		void	makeSound() const;
};



#endif
