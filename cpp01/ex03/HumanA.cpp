#include "HumanA.hpp"

#include <iostream>
#include <string>

#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
    : name_(name), weapon_(weapon) {}
void HumanA::attack(void) {
  std::cout << name_ << " attacks with their " << weapon_.getType()
            << std::endl;
}
