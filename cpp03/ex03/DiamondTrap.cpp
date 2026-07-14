#include "DiamondTrap.hpp"

#include <iostream>
#include <string>

DiamondTrap::DiamondTrap()
    : ClapTrap("unknown_clap_name", 100, 50, 30),
      ScavTrap("unknown"),
      FragTrap("unknown"),
      name_("unknown") {
  std::cout << getName() << " DiamondTrap default constructor called"
            << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name", 100, 50, 30),
      ScavTrap(name),
      FragTrap(name),
      name_(name) {
  std::cout << getName() << " DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(static_cast<const ClapTrap&>(other)),
      ScavTrap(static_cast<const ScavTrap&>(other)),
      FragTrap(static_cast<const FragTrap&>(other)),
      name_(other.name_) {
  std::cout << getName() << " DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  if (this != &other) {
    this->ClapTrap::operator=(static_cast<const ClapTrap&>(other));
    this->name_ = other.name_;
  }
  std::cout << getName() << " DiamondTrap copy assignment operator called"
            << std::endl;
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << getName() << " DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "DaiamondTrap " << name_ << std::endl;
  std::cout << "CrapTrap " << DiamondTrap::ClapTrap::getName() << std::endl;
}
