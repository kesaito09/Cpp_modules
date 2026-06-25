#include "Weapon.hpp"

#include <string>

Weapon::Weapon(std::string type) : type_(type) {}
const std::string& Weapon::getType(void) const { return type_; }

void Weapon::setType(const std::string& type) { type_ = type; }
