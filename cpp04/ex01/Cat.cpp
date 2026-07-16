#include "Cat.hpp"

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), brain_(new Brain) {
  std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(static_cast<const Animal&>(other)),
      brain_(new Brain(*other.brain_)) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    this->Animal::operator=(other);
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

std::string Cat::getIdea(size_t idx) const {
  return brain_->getter(idx);
}

void Cat::setIdea(size_t idx, std::string idea) {
  brain_->setter(idx, idea);
}
