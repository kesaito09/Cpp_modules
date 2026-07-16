#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

std::string const& getType() const;
void use(ICharacter& target);
