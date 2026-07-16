#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
 private:
  Brain* brain_;

 public:
  Dog();
  Dog(const Dog&);
  Dog& operator=(const Dog&);
  virtual ~Dog();
  void makeSound() const;
  std::string getIdea(size_t idx) const;
  void setIdea(size_t idx, std::string);
};

#endif
