#include "HumanB.hpp"

#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}
void HumanB::attack(void) {
  if (!weapon_) return;
  std::cout << name_ << " attacks with their " << weapon_->getType()
            << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) { weapon_ = &weapon; }
