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
	std::size_t size = s.size();
    for (std::string::size_type j = 0; j < size; ++j)
      s[j] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[j])));
    std::cout << s;
  }
  std::cout << std::endl;
  return 0;
}

