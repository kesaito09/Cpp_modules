#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain {
 private:
  std::string ideas_[100];

 public:
  Brain();
  Brain(const Brain&);
  Brain& operator=(const Brain&);
  ~Brain();
};

#endif
