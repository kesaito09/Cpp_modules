#include <string>

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
  randomChump("bobbbbb");
  Zombie* delete_zombie = newZombie("delete");
  Zombie* nodelete_zombie = newZombie("no_delete");
  delete_zombie->announce();
  nodelete_zombie->announce();
  delete delete_zombie;
  delete nodelete_zombie;
  return 0;
}
