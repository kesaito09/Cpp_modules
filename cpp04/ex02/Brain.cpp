#include "Brain.hpp"

#include <iostream>
#include <string>

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(const Brain& other) {
  for (size_t i = 0; i < 100; ++i) {
    ideas_[i] = other.ideas_[i];
  }
  std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
  if (this != &other) {
    for (size_t i = 0; i < 100; ++i) {
      ideas_[i] = other.ideas_[i];
    }
  }
  std::cout << "Brain copy assignment operator called" << std::endl;
  return *this;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }
