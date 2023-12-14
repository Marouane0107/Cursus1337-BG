
#include "PhoneBook.hpp"

int	is_valid(std::string str, int c)
{
	int 	f = 0;
	size_t	j = 0;
	if (c == 1 || c == 2)
	{
		for(int i = 0; str[i]; i++)
		{
			f = isprint(str[i]);
			if (f == 0)
			{
				std::cout <<" Are you serious? ( Try again using valid input ) "<<std::endl;
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
	}
	if (c == 2)
	{
		for(size_t i = 0; i < str.length(); i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				std::cout <<" Invalid input !!"<<std::endl;
				return (1);
			}
		}	
	}
	return (0);
}

void	PhoneBook::print_view(int	count)
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
	for(int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << "|" ;
		str = phone[i].getfirst_name();
		if (phone[i].getfirst_name().size() > 10 )
		{
			str = phone[i].getfirst_name().substr(0,9);
			str.append(".");
		}
		std::cout << std::setw(10) << str << "|" ;
		str = phone[i].getlast_name();
		if (phone[i].getlast_name().size() > 10 )
		{
			str = phone[i].getlast_name().substr(0,9);
			str.append(".");
		}
		std::cout << std::setw(10) << str << "|";
		str = phone[i].getnickname();
		if (phone[i].getnickname().size() > 10 )
		{
			str = phone[i].getnickname().substr(0,9);
			str.append(".");
		}
		std::cout << std::setw(10) << str << "|" << std::endl;
	}
}

int	PhoneBook::get_info(int index)
{
	int	x;
	std::string	input;

	if (std::cin.eof())
		exit(0);
	std::cout << "Enter index : ";
	getline(std::cin, input) ;
	if (is_valid(input, 2) != 0)
	{
		return (1);
	}
	std::istringstream iss(input);
	iss >> x;
	if (x >= index || x < 0)
	{
		std::cout << " Invalid index !!" <<std::endl;
		return (1);
	}
	std::cout << "-------------------------------------------------- " << std::endl;
	std::cout << "first name : " << phone[x].getfirst_name() << std::endl;
	std::cout << "last name : " << phone[x].getlast_name() << std::endl;
	std::cout << "nickname : " << phone[x].getnickname() << std::endl;
	std::cout << "phone number : " << phone[x].getphone_number() << std::endl;
	std::cout << "darkest secret : " << phone[x].getdarkest_secret() << std::endl;
	std::cout << "-------------------------------------------------- " << std::endl;
	return (0);
}

int PhoneBook::add_contact(int x)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	if (std::cin.eof())
		exit(0);
	std::cout <<" first_name : "; 
	getline(std::cin, first_name);
	if (is_valid(first_name, 1))
		return (1);
	std::cout <<" last_name : "; 
	getline(std::cin, last_name);
	if (is_valid(last_name, 1))
		return (1);
	std::cout <<" nickname : "; 
	getline(std::cin, nickname);
	if (is_valid(nickname, 1))
		return (1);
	std::cout <<" phone_number : "; 
	getline(std::cin, phone_number);
	if (is_valid(phone_number, 1))
		return (1);
	std::cout <<" darkest_secret : "; 
	getline(std::cin, darkest_secret);
	if (is_valid(darkest_secret, 1))
		return (1);
	phone[x].setindex(x);
	phone[x].setfirst(first_name);
	phone[x].setlast(last_name);
	phone[x].setnickname(nickname);
	phone[x].setphone(phone_number);
	phone[x].setsecret(darkest_secret);
	std::cout << " ****** Your contact has been added successfully ****** " << std::endl;
	return (0);
}
