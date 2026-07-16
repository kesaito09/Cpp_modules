#include "Dog.hpp"

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), brain_(new Brain) {
  std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
    : Animal(static_cast<const Animal&>(other)),
      brain_(new Brain(*other.brain_)) {
  std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    this->Animal::operator=(other);
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
