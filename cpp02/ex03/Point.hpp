#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
 private:
  const Fixed x_;
  const Fixed y_;

 public:
  Point();
  Point(const float, const float);
  Point(const Fixed&, const Fixed&);
  Point(const Point&);
  ~Point();
  static Fixed cross(const Point&, const Point&);
  Point& operator=(const Point&);
  Point operator-(const Point&) const;
  Fixed operator*(const Point&) const;
};

#endif
