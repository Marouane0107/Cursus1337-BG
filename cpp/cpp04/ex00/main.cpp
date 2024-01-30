#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	return 0;
}

// int main()
// {
// 	Animal* a = new Animal();
// 	Animal* b = new Cat();
// 	Animal* c = new Dog();
// 	WrongAnimal* d = new WrongAnimal();
// 	WrongAnimal* e = new WrongCat();
// 	WrongCat* f = new WrongCat();

// 		std::cout << b->getType() << " " << std::endl;
// 		std::cout << c->getType() << " " << std::endl;
// 		std::cout << e->getType() << " " << std::endl;
// 		b->makeSound();
// 		c->makeSound();
// 		e->makeSound();

// 		a->makeSound();
// 		d->makeSound();

// 		f->makeSound();

// 	delete a;
// 	delete b;
// 	delete c;
// 	delete d;
// 	delete e;
// 	delete f;

// 	return (0);
// }