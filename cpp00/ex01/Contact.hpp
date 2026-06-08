#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>


class Contact
{
private:
	struct s_contact
	{
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string	phone_number;
		std::string	secret;
	};
	s_contact data;

public:
	bool		set(void);
	void		display_row(int index);
	void		display_details(void);

};

#endif
