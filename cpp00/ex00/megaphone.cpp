#include <cctype>
#include <iostream>
#include <string>

int main(int ac, char** av) {
  if (ac < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }
  for (int i = 1; i < ac; ++i) {
    std::string s = av[i];
    for (std::string::size_type j = 0; j < s.size(); ++j)
      s[j] = std::toupper(static_cast<unsigned char>(s[j]));
    std::cout << s;
  }
  std::cout << std::endl;
  return 0;
}

/*
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
*/