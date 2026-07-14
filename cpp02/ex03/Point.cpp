#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}
Point::Point(const Fixed& x, const Fixed& y) : x_(x), y_(y) {}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
  (void)other;
  return *this;
}

Point Point::operator-(const Point& other) const {
  return Point(this->x_ - other.x_, this->y_ - other.y_);
}

Fixed Point::operator*(const Point& other) const {
  return ((this->x_ * other.y_) - (this->y_ * other.x_));

}
