#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public A_Animal
{
	private:

		Brain *brain;
	public:
	
		Cat();
		~Cat();
		void	makeSound()const;
};



#endif