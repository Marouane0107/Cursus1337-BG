#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& o);
		Cat& operator=(const Cat& o);
		~Cat();
		void	makeSound()const;
};



#endif
