#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


// int main()
// {
// 	const A_Animal* j = new Dog();
// 	const A_Animal* i = new Cat();
	
// 	j->makeSound();
// 	i->makeSound();
// 	delete j; 
// 	delete i;

// 	return 0;
// }


int main()
{

	A_Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

	for(int i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
	}

	for(int i = 0; i < 4; i++)
	{
		delete animals[i];
	}
	return 0;
}

