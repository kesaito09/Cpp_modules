#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain* brain_;

 public:
  Cat();
  Cat(const Cat&);
  Cat& operator=(const Cat&);
  virtual ~Cat();
  void makeSound() const;
  std::string getIdea(size_t idx) const;
  void setIdea(size_t idx, std::string);
};

#endif
