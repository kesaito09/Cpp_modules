#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
 private:
  int value_;
  static const int fbits_;

 public:
  Fixed();
  Fixed(const Fixed&);
  ~Fixed();
  Fixed& operator=(const Fixed&);
  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
