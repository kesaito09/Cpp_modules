#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook()
{
	PhoneBook::count = 0;
}

void PhoneBook::add(void)
{
	Contact	new_contact;
	int		slot;

	slot = PhoneBook::count;
	if (!new_contact.set())
		return ;
	PhoneBook::contacts[slot % 8] = new_contact;
	PhoneBook::count++;
}

void	PhoneBook::display_header(void)
{
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" <<  "|";
	std::cout << std::setw(10) << "last name" <<  "|";
	std::cout << std::setw(10) << "nickname";
	std::cout << std::endl;
}

void PhoneBook::display_list(void)
{
	int	display_count = 0;

	PhoneBook::display_header();
	count >= 8 ? display_count = 8: display_count = count % 8;
	for (int i = 0; i < display_count; i++)
		PhoneBook::contacts[i].display_row(i);
}

void PhoneBook::search(void)
{
	unsigned int		index;
	std::string			line;
	char				check;

	PhoneBook::display_list();
	std::cout << "Enter index: ";
	std::getline(std::cin, line);
	std::stringstream ss(line);
	if (!(ss >> index) || ss >> check)
		return ;
	if (index >= 8 || index >= count)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	PhoneBook::contacts[index].display_details();
}
