#include "Fixed.hpp"

#include <cmath>
#include <iostream>

const int Fixed::fbits_ = 8;

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value_(other.value_) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value << fbits_) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : value_(roundf(value * (1 << fbits_))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) value_ = other.value_;
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  value_ = raw;
}

float Fixed::toFloat(void) const {
  return (value_ / static_cast<float>(1 << fbits_));
}

int Fixed::toInt(void) const { return value_ / (1 << fbits_); }

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
  out << obj.toFloat();
  return out;
}
