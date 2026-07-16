#include "Ice.hpp"

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria* Ice::clone(void) const { return new Ice; }

void Ice::use(ICharacter& target) {
  std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\""
            << std::endl;
}
