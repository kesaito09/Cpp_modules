#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal {
 protected:
  std::string type_;

 public:
  Animal();
  Animal(const Animal&);
  Animal(std::string);
  Animal& operator=(const Animal&);
  virtual ~Animal();
  virtual void makeSound(void) const;
  std::string getType(void) const;
};

#endif
