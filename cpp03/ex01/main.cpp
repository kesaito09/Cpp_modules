#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ScavTrap A = ScavTrap("A");
  ClapTrap B = ClapTrap("B");
  A.attack("attacking");
  A.guardGate();

  ClapTrap *p = new ScavTrap("X");
  p->attack("Y");
  delete p;
}

