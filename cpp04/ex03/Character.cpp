#include "Character.hpp"

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character() {}

Character::Character(std::string name) {}

Character::Character(const Character& other) : name_(other.name_) {
  for (int i = 0; i < 4; ++i) inventory[i] = NULL;
  for (int i = 0; i < 4; ++i) {
    if (other.inventory[i] != NULL) inventory[i] = other.inventory[i]->clone();
  }
}

Character& Character::operator=(const Character& other) {
  if (this != &other) {
    for (size_t i = 0; i < 4; ++i) {
      if (inventory[i] != NULL) {
        delete inventory[i];
		inventory[i] = NULL;
      }
    }
    for (size_t i = 0; i < 4; ++i) {
      if (other.inventory[i] != NULL) {
        inventory[i] = other.inventory[i]->clone();
      }
    }
    name_ = other.name_;
  }
  return *this;
}

Character::~Character() {
  for (size_t i = 0; i < 4; i++) {
    delete inventory[i];
  }
};

std::string const& Character::getName() const { return name_; }

void Character::equip(AMateria* m) {
  for (size_t i = 0; i < 4; ++i) {
    if (inventory[i] == 0) {
      inventory[i] = m;
      return;
    }
    if (i == 3) {
      std::cout << "inventry is full" << std::endl;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
    inventory[idx]->use(target);
  }
}
