#include <iostream>
#include <string>
#include "PhoneBook.hpp"

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

void	PhoneBook::print_view(int	x)
{
	std::string str;
	std::cout << std::setw(10) << "index" << "|" <<
	std::setw(10) << "first name" << "|" <<
	std::setw(10) << "last name" << "|" <<
	std::setw(10) << " nickname" << "|" << std::endl;
	std::cout << std::setw(10) << "----------" << "|" <<
	std::setw(10) << "----------" << "|" <<
	std::setw(10) << "----------" << "|" <<
	std::setw(10) << "----------" << "|" << std::endl;
	for(int i = 0; i < x; i++)
	{
		std::cout << std::setw(10) << i << "|" ;
		if (phone[i].getfirst_name().size() >= 10 )
		{
			str = phone[i].getfirst_name().substr(0,9);
			str.append(".");
		}
		//from here
		std::cout << std::setw(10) << str << "|" <<
		std::setw(10) << phone[i].getlast_name() << "|" <<
		std::setw(10) << phone[i].getnickname() << "|" << std::endl;
	}
	///need to finish the condition above
}

int PhoneBook::add_contact(int x)
{
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
	phone[x].setindex(x);
	phone[x].setfirst(first_name);
	phone[x].setlast(last_name);
	phone[x].setnickname(nickname);
	phone[x].setphone(phone_number);
	phone[x].setsecret(darkest_secret);
	return (0);
}

//appand
//substr