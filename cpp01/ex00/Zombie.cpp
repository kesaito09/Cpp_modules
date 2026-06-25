#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie(std::string name): name_(name) {}

Zombie::~Zombie() { std::cout << name_ << ": deleted" << std::endl; }

void Zombie::announce(void) {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
