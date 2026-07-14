#include <climits>
#include <iostream>
#include <string>

#include "DiamondTrap.hpp"

int main(void) {
  DiamondTrap dt = DiamondTrap("dt");
  DiamondTrap dt2 = DiamondTrap("dt2");
  std::cout << "------------------------" << std::endl;
  dt.whoAmI();
  std::cout << "------------------------" << std::endl;
  dt2.attack("from FragTrap");
  dt2.beRepaired(UINT_MAX);
  std::cout << "------------------------" << std::endl;
  dt = dt2;
  std::cout << "------------------------" << std::endl;
  dt.beRepaired(1);
  DiamondTrap dt3 = DiamondTrap(dt);
  dt3.beRepaired(1);
  std::cout << "------------------------" << std::endl;
  dt3.guardGate();
  dt3.highFivesGuys();
  std::cout << "------------------------" << std::endl;
}
