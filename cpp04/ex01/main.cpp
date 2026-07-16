#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << "----- Test 1: array of 10 Animal* (Dog/Cat mix) -----\n"
            << std::endl;
  const Animal* animals[10];
  for (size_t i = 0; i < 10; ++i) {
    animals[i] = (i % 2) ? static_cast<Animal*>(new Dog())
                          : static_cast<Animal*>(new Cat());
  }

  std::cout << "\n--- checking polymorphism (getType / makeSound) ---\n"
            << std::endl;
  for (size_t i = 0; i < 10; ++i) {
    std::cout << animals[i]->getType() << ": ";
    animals[i]->makeSound();
  }

  std::cout << "\n--- deleting all animals ---\n" << std::endl;
  for (size_t i = 0; i < 10; ++i) {
    delete animals[i];
  }

  std::cout << "\n----- Test 2: single Dog / Cat (leak check) -----\n"
            << std::endl;
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << "\n--- deleting ---\n" << std::endl;
  delete j;  // should not create a leak
  delete i;

  std::cout << "\n----- Test 3: Dog deep copy -----\n" << std::endl;
  Dog* dog = new Dog();
  dog->setIdea(0, "original");

  Dog* copy_dog = new Dog(*dog);  // copy constructor
  copy_dog->setIdea(0, "copy independent");
  std::cout << "dog->getIdea(0)      = " << dog->getIdea(0) << std::endl;
  std::cout << "copy_dog->getIdea(0) = " << copy_dog->getIdea(0)
            << std::endl;
  std::cout << "(values differ => deep copy OK)" << std::endl;

  Dog* assigned_dog = new Dog();
  *assigned_dog = *dog;  // assignment operator
  assigned_dog->setIdea(0, "assigned independent");
  std::cout << "dog->getIdea(0)          = " << dog->getIdea(0) << std::endl;
  std::cout << "assigned_dog->getIdea(0) = " << assigned_dog->getIdea(0)
            << std::endl;
  std::cout << "(values differ => deep copy OK)" << std::endl;

  *assigned_dog = *assigned_dog;  // self-assignment
  std::cout << "assigned_dog->getIdea(0) after self-assign = "
            << assigned_dog->getIdea(0) << " (should be unchanged)"
            << std::endl;

  delete dog;
  delete copy_dog;
  delete assigned_dog;

  std::cout << "\n----- Test 4: WrongAnimal / WrongCat -----\n" << std::endl;
  const WrongAnimal* wrongMeta = new WrongAnimal();
  const WrongAnimal* wrongCat = new WrongCat();
  wrongMeta->makeSound();  // WrongAnimal sound
  wrongCat->makeSound();   // NOT overridden polymorphically: still WrongAnimal sound
  delete wrongMeta;
  delete wrongCat;

  std::cout << "\n----- done -----" << std::endl;
  return 0;
}
