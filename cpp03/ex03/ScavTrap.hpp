#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>

#include "ClapTrap.hpp"
class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap&);
  ~ScavTrap();
  ScavTrap& operator=(const ScavTrap&);
  void attack(const std::string&);
  void guardGate();
};

#endif
