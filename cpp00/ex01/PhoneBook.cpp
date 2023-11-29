#include <iostream>
#include <string>
#include "PhoneBook.hpp"


void	contact::print_view(int	x)
{
	std::cout << std::setw(10) << "index" << "|" <<
	std::setw(10) << "first name" << "|" <<
	std::setw(10) << "last name" << "|" <<
	std::setw(10) << " nickname" << "|" << std::endl;
	std::cout << std::setw(10) << "" << "|" <<
	std::setw(10) << "" << "|" <<
	std::setw(10) << "" << "|" <<
	std::setw(10) << "" << "|" << std::endl;
}

int	is_valid(std::string str)
{
	int f = 0;
	int	j = 0;
	for(int i = 0; str[i]; i++)
	{
		f = isprint(str[i]);
		if (f == 0)
		{
			std::cout <<" Invalid information !!"<<std::endl;
			return (1);
		}
		if (str[i] == ' ')
			j++;
	}
	if (j == str.length())
	{
		std::cout <<" Invalid information !!"<<std::endl;
			return (1);
	}
	return (0);
}

int contact::add_contact(int x)
{
	contact contact;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout <<" first_name : "; 
	getline(std::cin, first_name);
	if (is_valid(first_name))
		return (1);
	std::cout <<" last_name : "; 
	getline(std::cin, last_name);
	if (is_valid(last_name))
		return (1);
	std::cout <<" nickname : "; 
	getline(std::cin, nickname);
	if (is_valid(nickname))
		return (1);
	std::cout <<" phone_number : "; 
	getline(std::cin, phone_number);
	if (is_valid(phone_number))
		return (1);
	std::cout <<" darkest_secret : "; 
	getline(std::cin, darkest_secret);
	if (is_valid(darkest_secret))
		return (1);
	contact.index = x;
	contact.first_name = first_name;
	contact.last_name = last_name;
	contact.nickname = nickname;
	contact.phone_number = phone_number;
	contact.darkest_secret = darkest_secret;
	return (0);
}
