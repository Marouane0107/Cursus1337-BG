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
		Dog(const Dog& o);
		Dog& operator=(const Dog& o);
		~Dog();
		void	makeSound() const;
		Brain*	getbrain(void) const;
};



#endif
