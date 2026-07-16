#include <iostream>

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  std::cout << "----- Test : AAnimal*  -----\n"
            << std::endl;
  AAnimal* dog = new Dog();
  AAnimal* cat = new Cat();

  dog->makeSound();
  cat->makeSound();
  std::cout << "\n----- done -----" << std::endl;
  return 0;
}
