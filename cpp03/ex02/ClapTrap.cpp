#include "ClapTrap.hpp"

#include <climits>
#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string name)
    : name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
  std::cout << name_ << " ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name_(other.name_),
      hitPoints_(other.hitPoints_),
      energyPoints_(other.energyPoints_),
      attackDamage_(other.attackDamage_) {}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints,
                   unsigned int energyPoints, unsigned int attackDamage)
    : name_(name),
      hitPoints_(hitPoints),
      energyPoints_(energyPoints),
      attackDamage_(attackDamage) {
  std::cout << name_ << " ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << name_ << " ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  if (this != &other) {
    name_ = other.name_;
    hitPoints_ = other.hitPoints_;
    energyPoints_ = other.energyPoints_;
    attackDamage_ = other.attackDamage_;
  }
  std::cout << name_ << " ClapTrap copy assignment operator called" << std::endl;
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
  unsigned int repair;
  if (energyPoints_ > 0 && hitPoints_ > 0) {
    long valid = static_cast<long>(hitPoints_) + amount;
    if (hitPoints_ == UINT_MAX)
      repair = 0;
    else if (valid > UINT_MAX) {
      repair = UINT_MAX - hitPoints_;
      hitPoints_ = UINT_MAX;
      std::cout << "over flow detected!!" << std::endl;
    } else {
      hitPoints_ += amount;
      repair = amount;
    }
    --energyPoints_;
    std::cout << "ClapTrap " << name_ << " is repaired " << repair << " HP"
              << std::endl;
  } else
    std::cout << "ClapTrap " << name_
              << " can't be repaired: no hit points or energy left!"
              << std::endl;
}

std::string ClapTrap::getName(void) const { return name_; }
unsigned int ClapTrap::getHitpoints(void) const { return hitPoints_; }
unsigned int ClapTrap::getEnergyPoints(void) const { return energyPoints_; }
unsigned int ClapTrap::getAttackDamage(void) const { return attackDamage_; }

void ClapTrap::setName(std::string name) { name_ = name; }
void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
  energyPoints_ = energyPoints;
}
void ClapTrap::setHitPoints(unsigned int hitPoints) { hitPoints_ = hitPoints; }
void ClapTrap::setAttackDamage(unsigned int attackDamage) {
  attackDamage_ = attackDamage;
}
