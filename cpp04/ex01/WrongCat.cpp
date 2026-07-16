#include "WrongCat.hpp"

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(static_cast<const WrongAnimal&>(other)) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  if (this != &other) {
    this->WrongAnimal::operator=(other);
  }
  std::cout << "WrongCat copy assignment operator called" << std::endl;
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const { std::cout << "meow meow" << std::endl; }
