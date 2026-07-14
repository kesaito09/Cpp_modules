#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  FragTrap Frag = FragTrap("Frag");
  ClapTrap Clap = ClapTrap("Clap");
  ScavTrap Scav = ScavTrap("Scav");
  Frag.attack("anyone");
  Scav.attack("anyone");
  Frag.highFivesGuys();

  ClapTrap* p = new FragTrap("frag_new");
  p->attack("anyone");
  p = new ScavTrap("scav_new");
  p->attack("anyone");
  delete p;
}
