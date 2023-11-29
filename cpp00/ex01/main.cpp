#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main(int ac, char *av[])
{
	contact contact;
	std::string	command;	
	int index = 0;

	if (ac != 1)
		return(1);
	std::cout << "Enter one of the three commands (ADD, SEARCH, EXIT) : " << std::endl;
	while (getline(std::cin, command))
	{
		if (command.compare("EXIT") == 0)
		{
			exit(0);
		}
		if (command.compare("ADD") == 0)
		{
			if (index == 8)
				index = 0;
			contact.add_contact(index);
			index ++;
		}
		if (command.compare("SEARCH") == 0)
		{
			contact.print_view(index);
		}
		else
			std::cout << "Enter one of this three commands (ADD, SEARCH, EXIT) : " << std::endl;
	}
}