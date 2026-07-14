#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
 private:
  int value_;
  static const int fbits_;

 public:
  Fixed();
  Fixed(const Fixed&);
  Fixed(const int);
  Fixed(const float);
  ~Fixed();
  Fixed& operator=(const Fixed&);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};
std::ostream& operator<<(std::ostream&, const Fixed&);

#endif