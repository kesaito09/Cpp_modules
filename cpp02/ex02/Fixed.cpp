#include "Fixed.hpp"

#include <cmath>
#include <iostream>

const int Fixed::fbits_ = 8;

Fixed::Fixed() : value_(0) {}

Fixed::Fixed(const Fixed& other) : value_(other.value_) {}

Fixed::Fixed(int value) : value_(value << fbits_) {}

Fixed::Fixed(float value)
    : value_(static_cast<int>(roundf(value * (1 << fbits_)))) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) value_ = other.value_;
  return *this;
}

int Fixed::getRawBits(void) const { return value_; }

void Fixed::setRawBits(int const raw) { value_ = raw; }

float Fixed::toFloat(void) const {
  return (value_ / static_cast<float>(1 << fbits_));
}

int Fixed::toInt(void) const { return value_ / (1 << fbits_); }

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
  out << obj.toFloat();
  return out;
}

bool Fixed::operator>(const Fixed& obj) const {
  return this->value_ > obj.value_;
}

bool Fixed::operator<(const Fixed& obj) const {
  return this->value_ < obj.value_;
}

bool Fixed::operator>=(const Fixed& obj) const {
  return this->value_ >= obj.value_;
}

bool Fixed::operator<=(const Fixed& obj) const {
  return this->value_ <= obj.value_;
}

bool Fixed::operator==(const Fixed& obj) const {
  return this->value_ == obj.value_;
}
bool Fixed::operator!=(const Fixed& obj) const {
  return this->value_ != obj.value_;
}

Fixed Fixed::operator+(const Fixed& obj) const {
  Fixed newobj;
  newobj.value_ = value_ + obj.value_;
  return newobj;
}

Fixed Fixed::operator-(const Fixed& obj) const {
  Fixed newobj;
  newobj.value_ = value_ - obj.value_;
  return newobj;
}

Fixed Fixed::operator*(const Fixed& obj) const {
  Fixed newobj;
  long product = static_cast<long>(value_) * obj.value_;
  newobj.value_ = static_cast<int>(product / (1 << fbits_));
  return newobj;
}

Fixed Fixed::operator/(const Fixed& obj) const {
  Fixed newobj;
  long tmp = static_cast<long>(value_) * (1 << fbits_);
  newobj.value_ = static_cast<int>(tmp / obj.value_);
  return newobj;
}

Fixed& Fixed::operator++() {
  ++(this->value_);
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed old(*this);
  ++(*this);
  return old;
}

Fixed& Fixed::operator--() {
  --(this->value_);
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed old(*this);
  --(*this);
  return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a > b ? b : a); }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  return (a > b ? b : a);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b ? a : b); }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return (a > b ? a : b);
}
