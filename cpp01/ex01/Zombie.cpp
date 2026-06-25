#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie::~Zombie() { std::cout << name_ << ": deleted" << std::endl; }

void Zombie::set(const std::string& name) { name_ = name; }

void Zombie::announce(void) {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
