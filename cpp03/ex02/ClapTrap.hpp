#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
class ClapTrap {
 private:
  std::string name_;
  unsigned int hitPoints_;
  unsigned int energyPoints_;
  unsigned int attackDamage_;

 protected:
  ClapTrap(std::string, unsigned int, unsigned int , unsigned int);
  std::string getName(void) const;
  unsigned int getHitpoints(void) const;
  unsigned int getEnergyPoints(void) const;
  unsigned int getAttackDamage(void) const;
  void setName(std::string);
  void setHitPoints(unsigned int);
  void setEnergyPoints(unsigned int);
  void setAttackDamage(unsigned int);

 public:
  ClapTrap(std::string);
  ClapTrap(const ClapTrap&);
  virtual ~ClapTrap();
  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  ClapTrap& operator=(const ClapTrap&);
};

#endif
