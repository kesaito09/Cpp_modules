#include "Dog.hpp"

#include <iostream>
#include <string>

#include "AAnimal.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal("Dog"), brain_(new Brain) {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
    : AAnimal(static_cast<const AAnimal&>(other)),
      brain_(new Brain(*other.brain_)) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    this->AAnimal::operator=(other);
    *brain_ = *other.brain_;
  }
  std::cout << "Dog copy assignment operator called" << std::endl;
  return *this;
}

Dog::~Dog() {
  delete brain_;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const { std::cout << "wow wow" << std::endl; }
