#include "FragTrap.hpp"

#include <iostream>
#include <string>

FragTrap::FragTrap() : ClapTrap("unknown", 100, 100, 30) {
  std::cout << getName() << " FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
  std::cout << getName() << " FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(static_cast<const ClapTrap&>(other)) {
  std::cout << getName() << " FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  if (this != &other) {
    this->ClapTrap::operator=(static_cast<const ClapTrap&>(other));
  }
  std::cout << getName() << " FragTrap copy assignment operator called"
            << std::endl;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << getName() << " FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << getName() << " FragTrap highfive" << std::endl;
}
