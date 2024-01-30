
#include "PhoneBook.hpp"

int main(int ac, char *av[])
{
	contact contact;
	PhoneBook PhoneBook;
	std::string	command;	
	(void)(av);
	int index = 0;
	int	count = 0;

	if (ac != 1)
	{
		std::cout << "Invalid number of argument !!" << std::endl;
		return(1);
	}
	std::cout << "Enter one of the three commands (ADD, SEARCH, EXIT) : " ;
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
			while (1)
			{
				if (!PhoneBook.add_contact(index))
				{
					index ++;
					if (count < 8)
						count++;
					break;
				}
			}
		}
		if (command.compare("SEARCH") == 0)
		{
			PhoneBook.print_view(count);
			if (index > 0)
			{
				while(1)
				{
					if (!PhoneBook.get_info(index))
					{
						std::cout << "Enter one of this three commands (ADD, SEARCH, EXIT) : " ;
						break;
					}
				}
			}
			else
			{
				std::cout << "There is no contact to see ! ->use 'ADD' and try again ;)" << std::endl;
				std::cout << "Enter one of this three commands (ADD, SEARCH, EXIT) : " ;
			}
		}
		else
			std::cout << "Enter one of this three commands (ADD, SEARCH, EXIT) : " ;
	}
}
