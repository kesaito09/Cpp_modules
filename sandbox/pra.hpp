#ifndef PRA_HPP
#define PRA_HPP

#include <string>


class Human
{
private:
	std::string _name;
public:
	std::string	get() const;
	void		set(std::string name);
	~Human();
};

	




#endif 