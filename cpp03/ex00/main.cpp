#include <climits>
#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
  // UINT_MAX == 4,294,967,295

  ClapTrap A = ClapTrap("A");
  //==HPの最大値を超えるケース==
  A.beRepaired(UINT_MAX - 20);
  A.beRepaired(11);
  A.beRepaired(11);

  ClapTrap B = ClapTrap("B");
  ClapTrap C = ClapTrap("C");
  B.attack("C");
  B.takeDamage(1000);
  C.attack("B");
  C = B;
  C.attack("B");
  ClapTrap D = ClapTrap(C);
  D.attack("B");
}
