#include "Cat.hpp"

#include <iostream>
#include <string>

#include "Animal.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "Cat constructor called" << std::endl; }

Cat::Cat(const Cat& other) : Animal(static_cast<const Animal&>(other)) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    this->Animal::operator=(other);
  }
  std::cout << "Cat copy assignment operator called" << std::endl;
  return *this;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound(void) const {
  std::cout << "meow meow" << std::endl;
}
