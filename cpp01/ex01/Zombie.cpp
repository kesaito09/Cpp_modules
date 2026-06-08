#include "Zombie.hpp"
#include <string>
#include <iostream>


Zombie::~Zombie()
{
	std::cout << name << ": deleted" << std::endl;
}

void	Zombie::set(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}
