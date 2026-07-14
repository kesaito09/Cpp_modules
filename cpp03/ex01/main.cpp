#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

// int main(void) {
//   ScavTrap A = ScavTrap("A");
//   ClapTrap B = ClapTrap("b");
//   A.attack("attacking!!");
//   A.guardGate();

//   ClapTrap *p = new ScavTrap("X");
//   p->attack("Y");
//   delete p;
// }

int main(void) {
  // 4,294,967,295

  ClapTrap A = ClapTrap("A");
  //==HPの最大値を超えるケース==
  A.beRepaired(UINT_MAX - 20);
  A.beRepaired(11);

  //   A.attack("B");
  //   A.takeDamage(UINT_MAX);
  //   A.attack("C");
  //   A.beRepaired(UINT_MAX);
  //   A.beRepaired(UINT_MAX);
  //   A.takeDamage(10);
  //   A.beRepaired(11);
  //   A.attack("D");
  //   A.attack("D");
  //   A.attack("D");

  //   ClapTrap B = ClapTrap("B");
  //   ClapTrap C = ClapTrap("C");
  //   B.attack("C");
  //   B.takeDamage(1000);
  //   C.attack("B");
  //   C = B;
  //   C.attack("B");
}
