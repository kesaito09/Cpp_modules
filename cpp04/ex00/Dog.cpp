#include "Dog.hpp"

#include <iostream>
#include <string>

#include "Animal.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(static_cast<const Animal&>(other)) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    this->Animal::operator=(other);
  }
  std::cout << "Dog copy assignment operator called" << std::endl;
  return *this;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

void Dog::makeSound(void) const { std::cout << "wow wow" << std::endl; }
