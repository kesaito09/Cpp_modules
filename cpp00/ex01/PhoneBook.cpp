#include "PhoneBook.hpp"

#include <iostream>
#include <sstream>
#include <string>

bool input(Contact::s_contact* data);
void logger(std::string msg);

PhoneBook::PhoneBook() { _count = 0; }

void PhoneBook::add(void) {
  Contact new_contact;
  Contact::s_contact data;
  int slot;

  slot = _count;
  if (!input(&data)) return;
  if (!new_contact.validate_format(data))
    return logger("Contact not saved: all fields are required.");
  new_contact.set(data);
  _contacts[slot % 8] = new_contact;
  _count++;
}

void PhoneBook::display_list(void) const {
  int display_count = 0;

  Contact::display_header();
  if (_count >= 8)
    display_count = 8;
  else
    display_count = _count;
  for (int i = 0; i < display_count; ++i) _contacts[i].display_row(i);
}

void PhoneBook::search(void) const {
  unsigned int index;
  std::string line;
  char check;

  display_list();
  std::cout << "Enter index: ";
  if (!(std::getline(std::cin, line))) return;
  std::stringstream ss(line);
  if (!(ss >> index) || ss >> check) return logger("Invalid index");
  if (index >= 8 || index >= _count) return logger("Invalid index");
	_contacts[index].display_details();
}
