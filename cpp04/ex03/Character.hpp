#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

#include "Floor.hpp"
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
 private:
  std::string name_;
  AMateria* inventory[4];
  Floor floor_;

 public:
  Character();
  Character(std::string const& name);
  Character(Character const& other);
  virtual ~Character();
  Character& operator=(Character const& other);

  std::string const& getName() const;
  void equip(AMateria* m);
  void unequip(int idx);
  void use(int idx, ICharacter& target);
};

#endif
