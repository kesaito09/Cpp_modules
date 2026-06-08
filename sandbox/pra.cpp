#include <iostream>
#include <string>
#include "pra.hpp"

std::string Human::get() const
{
	return _name;
}

void Human::set(std::string name)
{
	_name = name;
}

Human::~Human()
{
	std::cout << "init human";
}

int main(void)
{
	Human philo;
	
	philo.set("tinkoha");
	std::cout << philo.get();
	return 0;
}
