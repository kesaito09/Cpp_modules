#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>

class WrongAnimal {
 protected:
  std::string type_;

 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal&);
  WrongAnimal(std::string);
  WrongAnimal& operator=(const WrongAnimal&);
  virtual ~WrongAnimal();
  void makeSound(void) const;
  std::string getType(void) const;
};

#endif
