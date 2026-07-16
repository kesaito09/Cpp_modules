#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
 private:
  Brain* brain_;

 public:
  Cat();
  Cat(const Cat&);
  Cat& operator=(const Cat&);
  virtual ~Cat();
  void makeSound() const;
};

#endif
