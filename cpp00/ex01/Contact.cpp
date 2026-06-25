#include "Contact.hpp"

#include <iomanip>
#include <iostream>
#include <string>

void Contact::Set(const Contact::ContactData& data) {
  data_.first_name = data.first_name;
  data_.last_name = data.last_name;
  data_.nick_name = data.nick_name;
  data_.phone_number = data.phone_number;
  data_.secret = data.secret;
}

bool Contact::IsEmptyField(const std::string& field) {
  size_t pos = field.find_first_not_of(" \t");
  return (pos == std::string::npos);
}

bool Contact::ValidateFormat(const ContactData& data) {
  if (IsEmptyField(data.first_name)) return false;
  if (IsEmptyField(data.last_name)) return false;
  if (IsEmptyField(data.nick_name)) return false;
  if (IsEmptyField(data.phone_number)) return false;
  if (IsEmptyField(data.secret)) return false;
  return true;
}

std::string Contact::FormatField(const std::string& field) {
  if (field.length() > 10) return field.substr(0, 9) + ".";
  return field;
}

void Contact::DisplayHeader(void) {
  std::cout << std::setw(10) << "index" << "|";
  std::cout << std::setw(10) << "first name" << "|";
  std::cout << std::setw(10) << "last name" << "|";
  std::cout << std::setw(10) << "nickname";
  std::cout << std::endl;
}

void Contact::DisplayRow(int index) const {
  std::cout << std::setw(10) << index << "|";
  std::cout << std::setw(10) << FormatField(data_.first_name) << "|";
  std::cout << std::setw(10) << FormatField(data_.last_name) << "|";
  std::cout << std::setw(10) << FormatField(data_.nick_name);
  std::cout << std::endl;
}

void Contact::DisplayDetails(void) const {
  std::cout << "First name: " << data_.first_name << "\n";
  std::cout << "Last name: " << data_.last_name << "\n";
  std::cout << "Nickname: " << data_.nick_name << "\n";
  std::cout << "Phone number: " << data_.phone_number << "\n";
  std::cout << "Darkest secret: " << data_.secret << "\n";
  std::cout << std::endl;
}
