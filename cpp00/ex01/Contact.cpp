#include "Contact.hpp"

#include <iomanip>
#include <iostream>
#include <string>

void Contact::set(Contact::s_contact& data) {
  this->_data.first_name = data.first_name;
  this->_data.last_name = data.last_name;
  this->_data.nick_name = data.nick_name;
  this->_data.phone_number = data.phone_number;
  this->_data.secret = data.secret;
}

bool Contact::is_empty_field(const std::string& field) {
  size_t pos = field.find_first_not_of(" \t");
  return (pos == std::string::npos);
}

bool Contact::validate_format(const s_contact& data) {
  if (is_empty_field(data.first_name)) return false;
  if (is_empty_field(data.last_name)) return false;
  if (is_empty_field(data.nick_name)) return false;
  if (is_empty_field(data.phone_number)) return false;
  if (is_empty_field(data.secret)) return false;
  return true;
}

std::string Contact::format_field(const std::string& field) {
  if (field.length() > 10) return field.substr(0, 9) + ".";
  return field;
}

void Contact::display_header(void) {
  std::cout << std::setw(10) << "index" << "|";
  std::cout << std::setw(10) << "first name" << "|";
  std::cout << std::setw(10) << "last name" << "|";
  std::cout << std::setw(10) << "nickname";
  std::cout << std::endl;
}

void Contact::display_row(int index) const {
  std::cout << std::setw(10) << index << "|";
  std::cout << std::setw(10) << format_field(_data.first_name) << "|";
  std::cout << std::setw(10) << format_field(_data.last_name) << "|";
  std::cout << std::setw(10) << format_field(_data.nick_name);
  std::cout << std::endl;
}

void Contact::display_details(void) const {
  std::cout << "First name: " << _data.first_name << "\n";
  std::cout << "Last name: " << _data.last_name << "\n";
  std::cout << "Nickname: " << _data.nick_name << "\n";
  std::cout << "Phone number: " << _data.phone_number << "\n";
  std::cout << "Darkest secret: " << _data.secret << "\n";
  std::cout << std::endl;
}

// int main(void)
// {
// 	Contact contact_A;

// 	contact_A.set();
// 	contact_A.display();
// 	return 0;
// }
