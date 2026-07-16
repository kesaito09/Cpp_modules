#include "Cat.hpp"

#include <iostream>
#include <string>

#include "AAnimal.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal("Cat"), brain_(new Brain) {
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
    : AAnimal(static_cast<const AAnimal&>(other)),
      brain_(new Brain(*other.brain_)) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    this->AAnimal::operator=(other);
    *brain_ = *other.brain_;
  }
  std::cout << "Cat copy assignment operator called" << std::endl;
  return *this;
}

Cat::~Cat() {
  delete brain_;
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const { std::cout << "meow meow" << std::endl; }
