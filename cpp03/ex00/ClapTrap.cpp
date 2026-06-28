#include "ClapTrap.hpp"

#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << name_ << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name_(other.name_),
      hitPoints_(other.hitPoints_),
      energyPoints_(other.energyPoints_),
      attackDamage_(other.attackDamage_) {};

ClapTrap::~ClapTrap() {
  std::cout << name_ << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  if (this != &other) {
    name_ = other.name_;
    hitPoints_ = other.hitPoints_;
    energyPoints_ = other.energyPoints_;
    attackDamage_ = other.attackDamage_;
  }
  return *this;
}

void ClapTrap::attack(const std::string& target) {
  if (energyPoints_ > 0 && hitPoints_ > 0) {
    --energyPoints_;
    std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing "
              << attackDamage_ << " points of damage!" << std::endl;
  } else
    std::cout << "ClapTrap " << name_
              << " can't attack: no hit points or energy left!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap " << name_ << " takes " << amount << " damage!"
            << std::endl;
  hitPoints_ = hitPoints_ >= amount ? hitPoints_ - amount : 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energyPoints_ > 0 && hitPoints_ > 0) {
    std::cout << "ClapTrap " << name_ << " is repaired " << amount << " HP"
              << std::endl;
    hitPoints_ += amount;
    --energyPoints_;
  } else
    std::cout << "ClapTrap " << name_
              << " can't be repaired: no hit points or energy left!"
              << std::endl;
}
