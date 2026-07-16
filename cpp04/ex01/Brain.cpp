#include "Brain.hpp"

#include <iostream>
#include <string>

Brain::Brain() { std::cout << "Brain Default constructor called" << std::endl; }

Brain::Brain(const Brain& other) {
  for (size_t i = 0; i < 100; ++i) {
    ideas_[i] = other.ideas_[i];
  }
  std::cout << "Brain Copy constructor called" << std::endl;
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

Brain::~Brain() {
  std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getter(size_t idx) const { return ideas_[idx]; }

void Brain::setter(size_t idx, std::string idea) { ideas_[idx] = idea; }
