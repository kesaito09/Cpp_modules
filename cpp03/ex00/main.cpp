#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
  ClapTrap A = ClapTrap("A");
  A.attack("B");
  A.takeDamage(1000);
  A.attack("C");
//   A.beRepaired(20);
  A.attack("D");
  A.attack("D");
  A.attack("D");
}
