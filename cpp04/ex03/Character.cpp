#include "Character.hpp"

#include "AMateria.hpp"

Character::Character() : name_("") {
  for (int i = 0; i < 4; ++i) inventory[i] = NULL;
}

Character::Character(std::string const& name) : name_(name) {
  for (int i = 0; i < 4; ++i) inventory[i] = NULL;
}

Character::Character(Character const& other) : name_(other.name_), floor_(other.floor_) {
  for (int i = 0; i < 4; ++i) inventory[i] = NULL;
  for (int i = 0; i < 4; ++i) {
    if (other.inventory[i] != NULL) inventory[i] = other.inventory[i]->clone();
  }
}

Character& Character::operator=(Character const& other) {
  if (this != &other) {
    for (size_t i = 0; i < 4; ++i) {
      delete inventory[i];
      inventory[i] = NULL;
    }
    for (size_t i = 0; i < 4; ++i) {
      if (other.inventory[i] != NULL) {
        inventory[i] = other.inventory[i]->clone();
      }
    }
    floor_ = other.floor_;
    name_ = other.name_;
  }
  return *this;
}

Character::~Character() {
  for (size_t i = 0; i < 4; i++) {
    delete inventory[i];
    inventory[i] = NULL;
  }
}

std::string const& Character::getName() const { return name_; }

void Character::equip(AMateria* material) {
  if (material == NULL) return;
  for (size_t i = 0; i < 4; ++i) {
    if (inventory[i] == NULL) {
      inventory[i] = material;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
    floor_.drop(inventory[idx]);
    inventory[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= 0 && idx < 4 && inventory[idx] != NULL) {
    inventory[idx]->use(target);
  }
}
