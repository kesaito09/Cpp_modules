#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::~Zombie()
{
	std::cout << name << std::endl;
	delete Zombie;
}

void	Zombie::announce(void)
{
	std::cout << name + ": " << ": BraiiiiiiinnnzzzZ.." << std::endl;
}
