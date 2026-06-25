#include <iostream>
#include <string>

#include "PhoneBook.hpp"

void Logger(const std::string& msg);

int main(void) {
  std::string command;
  PhoneBook phonebook;

  while (1) {
    std::cout << "ADD or SEARCH or EXIT: ";
    if (!(std::getline(std::cin, command))) {
      Logger("\nByebye ^^");
      return 0;
    }
    if (command == "ADD")
      phonebook.Add();
    else if (command == "SEARCH")
      phonebook.Search();
    else if (command == "EXIT") {
      Logger("\nByebye ^^");
      return 0;
    }
    if (!std::cin) {
      Logger("\nByebye ^^");
      return 0;
    }
  }
}
