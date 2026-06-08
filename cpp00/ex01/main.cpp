#include <string>
#include <iostream>
#include "PhoneBook.hpp"


int main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	while (1)
	{
		std::cout << "ADD or SEARCH or EXIT: ";
		if (!(std::getline(std::cin, command)))
			return 0;
		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			return 0;
		if (!std::cin)
			return 0;		
	}
}
