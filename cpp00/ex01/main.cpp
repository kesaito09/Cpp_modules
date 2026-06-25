#include <iostream>
#include <string>

#include "PhoneBook.hpp"

void logger(std::string msg);

int main(void) {
  std::string command;
  PhoneBook phonebook;

  while (1) {
    std::cout << "ADD or SEARCH or EXIT: ";
    if (!(std::getline(std::cin, command))) return (logger("\nByebye ^^"), 0);
    if (command == "ADD")
      phonebook.add();
    else if (command == "SEARCH")
      phonebook.search();
    else if (command == "EXIT")
      return (logger("\nBeybye ^^"), 0);
    if (!std::cin) return (logger("\nByebye ^^"), 0);
  }
}
