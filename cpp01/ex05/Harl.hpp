#ifndef HARL_HPP
#define HARL_HPP
#include <string>

class Harl {
 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  typedef void (Harl::*Harl_func)(void);
  struct LevelEntry {
    std::string name;
    Harl_func func;
  };

 public:
  void complain(std::string level);
};

#endif
