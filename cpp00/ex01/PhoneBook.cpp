#include "PhoneBook.hpp"

#include <iostream>
#include <sstream>
#include <string>

bool Input(Contact::ContactData* data);
void Logger(const std::string& msg);

PhoneBook::PhoneBook() : count_(0), head_(0) {}

void PhoneBook::Add(void) {
  Contact new_contact;
  Contact::ContactData data;

  if (!Input(&data)) return;
  if (!new_contact.ValidateFormat(data))
    return Logger("Contact not saved: all fields are required.");
  new_contact.Set(data);
  contacts_[count_ % 8] = new_contact;
  count_++;
  if (count_ >= 8) head_ = count_ % 8;
}

void PhoneBook::DisplayList(void) const {
  std::size_t display_count = (count_ >= 8) ? 8 : count_;

  Contact::DisplayHeader();
  for (std::size_t d = 0; d < display_count; ++d) {
    contacts_[(head_ + d) % 8].DisplayRow(d);
  }
}

void PhoneBook::Search(void) const {
  unsigned int index;
  std::string line;
  char check;

  DisplayList();
  std::cout << "Enter index: ";
  if (!(std::getline(std::cin, line))) return;
  std::stringstream ss(line);
  if (!(ss >> index) || ss >> check) return Logger("Invalid index");
  if (index >= 8 || index >= count_) return Logger("Invalid index");
  contacts_[(head_ + index) % 8].DisplayDetails();
}
