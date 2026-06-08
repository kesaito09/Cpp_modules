#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact			contacts[8];
	unsigned int	count;

public:

	PhoneBook();
	void	add();
	void	search();
	void	display_list();
	void	display_header(void);
};

#endif
