#include "Animal.hpp"

#include <iostream>
#include <string>

Animal::Animal() : type_("") {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : type_(type) {
  std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type_(other.type_) {
  std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    type_ = other.type_;
  }
  std::cout << "Animal copy assignment operator called" << std::endl;
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

void Animal::makeSound(void) const { std::cout << "Animal sound" << std::endl; }

std::string Animal::getType(void) const { return type_; }
