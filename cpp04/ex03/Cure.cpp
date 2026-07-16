#include "Cure.hpp"

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria* Cure::clone(void) const { return new Cure; }

void Cure::use(ICharacter& target) {
  std::cout << "Cure: \"* heals " << target.getName() << "’s wounds *\""
            << std::endl;
}
