#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {
 private:
  AMateria* templates[4];

 public:
  MateriaSource();
  MateriaSource(MateriaSource const& other);
  virtual ~MateriaSource();
  MateriaSource& operator=(MateriaSource const& other);
  void learnMateria(AMateria* material);
  AMateria* createMateria(std::string const& type);
};

#endif
