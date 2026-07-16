#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal {
 protected:
  std::string type_;

 public:
  AAnimal();
  AAnimal(const AAnimal&);
  AAnimal(std::string);
  AAnimal& operator=(const AAnimal&);
  virtual ~AAnimal();
  virtual void makeSound(void) const = 0;
  std::string getType(void) const;
};

#endif
