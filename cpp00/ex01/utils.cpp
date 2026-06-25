#include <iostream>
#include <string>

#include "Contact.hpp"

bool Input(Contact::ContactData* data) {
  std::cout << "First name: ";
  if (!(std::getline(std::cin, data->first_name))) return false;
  std::cout << "Last name: ";
  if (!(std::getline(std::cin, data->last_name))) return false;
  std::cout << "Nickname: ";
  if (!(std::getline(std::cin, data->nick_name))) return false;
  std::cout << "Phone number: ";
  if (!(std::getline(std::cin, data->phone_number))) return false;
  std::cout << "Darkest secret: ";
  if (!(std::getline(std::cin, data->secret))) return false;
  return true;
}

void Logger(const std::string& msg) { std::cout << msg << std::endl; }
