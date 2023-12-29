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
		Cat(const Cat& o);
		Cat& operator=(const Cat& o);
		~Cat();
		void	makeSound()const;
		Brain*	getbrain(void) const;
};



#endif
