#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <string>

class AMateria;

class MateriaSource {
 private:
 public:
  MateriaSource(/* args */);
  ~MateriaSource();
  void learnMateria(AMateria*);
  AMateria* createMateria(std::string const& type);
};

#endif
