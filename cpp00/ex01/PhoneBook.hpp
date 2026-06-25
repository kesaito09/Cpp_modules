#ifndef PHONE_BOOK_H_
#define PHONE_BOOK_H_
#include "Contact.hpp"
#include <string>

class PhoneBook {
 private:
  Contact contacts_[8];
  std::size_t count_;
  std::size_t head_;

 public:
  PhoneBook();
  void Add();
  void Search() const;
  void DisplayList() const;
};

#endif
