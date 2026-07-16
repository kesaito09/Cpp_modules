#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
 private:
  std::string name_;
  AMateria* inventory[4];

 public:
  Character();
  Character(std::string name);
  Character(const Character&);
  ~Character();
  Character& operator=(const Character&);

  std::string const& getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);
};

#endif
