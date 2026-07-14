#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
  return 0;
}

// int main(void) {
//   Fixed assigned_a;
//   assigned_a = Fixed(42.5f);
//   std::cout << "float: " << 42.5f << ", Fixed: " << assigned_a.toFloat()
//             << std::endl;

//   Fixed assigned_b(-7.25f);
//   const Fixed& assigned_b_source = assigned_b;
//   assigned_b = assigned_b_source;
//   std::cout << "float: " << -7.25f << ", Fixed: " << assigned_b.toFloat()
//             << std::endl;

//   const Fixed high(10.0f);
//   const Fixed low(5.0f);
//   const Fixed equal(10.0f);

//   std::cout << (high > low) << std::endl;
//   std::cout << (low > high) << std::endl;
//   std::cout << (low < high) << std::endl;
//   std::cout << (high < low) << std::endl;
//   std::cout << (high >= equal) << std::endl;
//   std::cout << (low >= high) << std::endl;
//   std::cout << (high <= equal) << std::endl;
//   std::cout << (high <= low) << std::endl;
//   std::cout << (high == equal) << std::endl;
//   std::cout << (high == low) << std::endl;
//   std::cout << (high != low) << std::endl;
//   std::cout << (high != equal) << std::endl;

//   std::cout << "float: " << 12.75f << ", Fixed: "
//             << (Fixed(10.5f) + Fixed(2.25f)).toFloat() << std::endl;
//   std::cout << "float: " << -8.25f << ", Fixed: "
//             << (Fixed(-10.5f) + Fixed(2.25f)).toFloat() << std::endl;
//   std::cout << "float: " << 8.25f << ", Fixed: "
//             << (Fixed(10.5f) - Fixed(2.25f)).toFloat() << std::endl;
//   std::cout << "float: " << -8.25f << ", Fixed: "
//             << (Fixed(2.25f) - Fixed(10.5f)).toFloat() << std::endl;
//   std::cout << "float: " << 7.0f << ", Fixed: "
//             << (Fixed(3.5f) * Fixed(2)).toFloat() << std::endl;
//   std::cout << "float: " << -7.0f << ", Fixed: "
//             << (Fixed(-3.5f) * Fixed(2)).toFloat() << std::endl;
//   std::cout << "float: " << 3.0f << ", Fixed: "
//             << (Fixed(7.5f) / Fixed(2.5f)).toFloat() << std::endl;
//   std::cout << "float: " << -3.0f << ", Fixed: "
//             << (Fixed(-7.5f) / Fixed(2.5f)).toFloat() << std::endl;

//   Fixed pre_inc_a(1.0f);
//   Fixed pre_inc_b(-1.0f);
//   ++pre_inc_a;
//   ++pre_inc_b;
//   std::cout << "float: " << 1.00390625f << ", Fixed: "
//             << pre_inc_a.toFloat() << std::endl;
//   std::cout << "float: " << -0.99609375f << ", Fixed: "
//             << pre_inc_b.toFloat() << std::endl;

//   Fixed post_inc_a(1.0f);
//   Fixed post_inc_b(-1.0f);
//   Fixed post_inc_result_a = post_inc_a++;
//   Fixed post_inc_result_b = post_inc_b++;
//   std::cout << "float: " << 1.0f << ", Fixed: "
//             << post_inc_result_a.toFloat() << std::endl;
//   std::cout << "float: " << 1.00390625f << ", Fixed: "
//             << post_inc_a.toFloat() << std::endl;
//   std::cout << "float: " << -1.0f << ", Fixed: "
//             << post_inc_result_b.toFloat() << std::endl;
//   std::cout << "float: " << -0.99609375f << ", Fixed: "
//             << post_inc_b.toFloat() << std::endl;

//   Fixed pre_dec_a(1.0f);
//   Fixed pre_dec_b(-1.0f);
//   --pre_dec_a;
//   --pre_dec_b;
//   std::cout << "float: " << 0.99609375f << ", Fixed: "
//             << pre_dec_a.toFloat() << std::endl;
//   std::cout << "float: " << -1.00390625f << ", Fixed: "
//             << pre_dec_b.toFloat() << std::endl;

//   Fixed post_dec_a(1.0f);
//   Fixed post_dec_b(-1.0f);
//   Fixed post_dec_result_a = post_dec_a--;
//   Fixed post_dec_result_b = post_dec_b--;
//   std::cout << "float: " << 1.0f << ", Fixed: "
//             << post_dec_result_a.toFloat() << std::endl;
//   std::cout << "float: " << 0.99609375f << ", Fixed: "
//             << post_dec_a.toFloat() << std::endl;
//   std::cout << "float: " << -1.0f << ", Fixed: "
//             << post_dec_result_b.toFloat() << std::endl;
//   std::cout << "float: " << -1.00390625f << ", Fixed: "
//             << post_dec_b.toFloat() << std::endl;

//   Fixed mutable_low(5.0f);
//   Fixed mutable_high(10.0f);
//   const Fixed const_low(5.0f);
//   const Fixed const_high(10.0f);
//   std::cout << "float: " << 5.0f << ", Fixed: "
//             << Fixed::min(mutable_low, mutable_high).toFloat() << std::endl;
//   std::cout << "float: " << 10.0f << ", Fixed: "
//             << Fixed::max(mutable_low, mutable_high).toFloat() << std::endl;
//   std::cout << "float: " << 5.0f << ", Fixed: "
//             << Fixed::min(const_low, const_high).toFloat() << std::endl;
//   std::cout << "float: " << 10.0f << ", Fixed: "
//             << Fixed::max(const_low, const_high).toFloat() << std::endl;

//   return 0;
// }
