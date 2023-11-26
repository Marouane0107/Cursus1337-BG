
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>

class contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
public:
	void		setfirst_name(std::string first_name) {first_name = first_name;}
	void		setlast_name(std::string last_name) {last_name = last_name;}
	void		setnickname(std::string nickname) {nickname = nickname;}
	void		setdarkest_secret(std::string darkest_secret) {darkest_secret = darkest_secret;}
	void		setphone_number(std::string phone_number) {phone_number = phone_number;}
};

#endif