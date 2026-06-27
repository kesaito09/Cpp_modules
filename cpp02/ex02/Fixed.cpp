#include "Fixed.hpp"

#include <cmath>
#include <iostream>

const int Fixed::fbits_ = 8;

Fixed::Fixed() : value_(0) {}

Fixed::Fixed(const Fixed& other) : value_(other.value_) {}

Fixed::Fixed(int value) : value_(value << fbits_) {}

Fixed::Fixed(float value)
    : value_(roundf(std::ldexp(static_cast<double>(value), fbits_))) {}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) value_ = other.value_;
  return *this;
}

int Fixed::getRawBits(void) const { return value_; }

void Fixed::setRawBits(int const raw) { value_ = raw; }

float Fixed::toFloat(void) const {
  return (std::ldexp(static_cast<double>(value_), -fbits_));
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
  Fixed newobj(this->toFloat() + obj.toFloat());
  return newobj;
}

Fixed Fixed::operator-(const Fixed& obj) const {
  Fixed newobj(this->toFloat() - obj.toFloat());
  return newobj;
}

Fixed Fixed::operator*(const Fixed& obj) const {
  Fixed newobj(this->toFloat() * obj.toFloat());
  return newobj;
}

Fixed Fixed::operator/(const Fixed& obj) const {
  Fixed newobj(this->toFloat() / obj.toFloat());
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
