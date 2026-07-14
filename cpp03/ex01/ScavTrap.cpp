#include "ScavTrap.hpp"

#include <iostream>
#include <string>

ScavTrap::ScavTrap() : ClapTrap("None", 100, 50, 20) {
  std::cout << getName() << " ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
  std::cout << getName() << " ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(static_cast<const ClapTrap&>(other)) {
  std::cout << getName() << " ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << getName() << " ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  if (this != &other) {
    this->ClapTrap::operator=(static_cast<const ClapTrap&>(other));
  }
  std::cout << getName() << " ScavTrap copy assignment operator called"
            << std::endl;
  return *this;
}

void ScavTrap::attack(const std::string& target) {
  std::string name = getName();
  unsigned int energyPoints = getEnergyPoints();
  unsigned int hitPoints = getHitpoints();
  if (energyPoints > 0 && hitPoints > 0) {
    setEnergyPoints(energyPoints - 1);
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
              << getAttackDamage() << " points of damage!" << std::endl;
  } else
    std::cout << "ScavTrap " << name
              << " can't attack: no hit points or energy left!" << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}
