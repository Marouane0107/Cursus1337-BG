#include "Cat.hpp"
#include "Dog.hpp"


// int main()
// {
// 	Animal *animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

// 	for(int i = 0; i < 4; i++)
// 	{
// 		animals[i]->makeSound();
// 	}

// 	for(int i = 0; i < 4; i++)
// 	{
// 		delete animals[i];
// 	}
// 	return 0;
// }

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	j->makeSound();
	i->makeSound();
	delete j; //should not create a leak
	delete i;

	return 0;
}


//valgrind --leak-check=full ./Brain