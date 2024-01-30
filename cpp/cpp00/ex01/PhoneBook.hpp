
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>

class contact
{
private:
	int	index;

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
public:
	void		setindex(int x) {index = x;}
	void		setfirst(std::string First) {first_name = First ;}
	void		setlast(std::string last) {last_name = last ;}
	void		setnickname(std::string Nickname) {nickname = Nickname ;}
	void		setphone(std::string Phone) {phone_number = Phone ;}
	void		setsecret(std::string secret) {darkest_secret = secret ;}
	int			getindex() {return (index);}
	std::string	getfirst_name() {return (first_name);}
	std::string	getlast_name() {return (last_name);}
	std::string	getnickname() {return (nickname);}
	std::string	getdarkest_secret() {return (darkest_secret);}
	std::string	getphone_number() {return (phone_number);}
};

class PhoneBook
{
	private:
		contact phone[8];
	public:
		int		add_contact(int x);
		void	print_view(int	count);
		int		get_info(int index);
};

#endif