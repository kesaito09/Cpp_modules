#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

bool	Contact::set(void)
{
	std::cout << "First name: ";
	if (!(std::getline(std::cin, data.first_name)) || data.first_name.empty())
		return false;
	std::cout << "Last name: ";
	if (!(std::getline(std::cin, data.last_name)) || data.last_name.empty())
		return false;
	std::cout << "Nickname: ";
	if (!(std::getline(std::cin, data.nick_name)) || data.nick_name.empty())
		return false;
	std::cout << "Phone number: ";
	if (!(std::getline(std::cin, data.phone_number)) || data.phone_number.empty())
		return false;
	std::cout << "Darkest secret: ";
	if (!(std::getline(std::cin, data.secret)) || data.secret.empty())
		return false;
	return true;
}

void	Contact::display_row(int index)
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << (data.first_name.length() > 10 ? data.first_name.substr(0, 9) + "." : data.first_name) <<  "|";
	std::cout << std::setw(10) << (data.last_name.length() > 10 ? data.last_name.substr(0, 9) + "." : data.last_name) <<  "|";
	std::cout << std::setw(10) << (data.nick_name.length() > 10 ? data.nick_name.substr(0, 9) + "." : data.nick_name);
	std::cout << std::endl;
}

void	Contact::display_details(void)
{
	std::cout << "First name: " << data.first_name << std::endl;
	std::cout << "Last name: " << data.last_name << std::endl;
	std::cout << "Nickname: " << data.nick_name << std::endl;
	std::cout << "Phone number: " << data.phone_number << std::endl;
	std::cout << "Darkest secret: " <<  data.secret << std::endl;
}

// int main(void)
// {
// 	Contact contact_A;

// 	contact_A.set();
// 	contact_A.display();
// 	return 0;
// }
