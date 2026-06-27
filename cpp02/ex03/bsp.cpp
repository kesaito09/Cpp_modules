#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed ap = Point::cross(b - a, point - a);
  Fixed bp = Point::cross(c - b, point - b);
  Fixed cp = Point::cross(a - c, point - c);

  if ((ap > 0 && bp > 0 && cp > 0) || (ap < 0 && bp < 0 && cp < 0)) return true;
  return false;
}
