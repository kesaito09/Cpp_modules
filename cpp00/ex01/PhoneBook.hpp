#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
#include "Contact.hpp"

class PhoneBook {
 private:
  Contact _contacts[8];
  unsigned int _count;

 public:
  PhoneBook();
  void add();
  void search() const;
  void display_list() const;
};

#endif
