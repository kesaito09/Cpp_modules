#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie {
 private:
  std::string name_;

 public:
  ~Zombie();
  void set(const std::string& name);
  void announce(void);
};

#endif
