#include "Zombie.hpp"
#include <string>

Zombie* newZombie(std::string name);
void randomChump( std::string name );

int main(void)
{
	randomChump("natakaha");
	Zombie*	delete_zombie = newZombie("delete");
	Zombie* nodelete_zombie = newZombie("no_delete");
	delete_zombie->announce();
	nodelete_zombie->announce();
	delete delete_zombie;
	delete nodelete_zombie;
	return 0;
}
