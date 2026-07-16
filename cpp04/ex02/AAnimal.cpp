#include "AAnimal.hpp"

#include <iostream>
#include <string>

AAnimal::AAnimal() : type_("") {
  std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type_(type) {
  std::cout << "AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type_(other.type_) {
  std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
  if (this != &other) {
    type_ = other.type_;
  }
  std::cout << "AAnimal copy assignment operator called" << std::endl;
  return *this;
}

AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

std::string AAnimal::getType(void) const { return type_; }
