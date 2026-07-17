#include "MateriaSource.hpp"

#include "AMateria.hpp"

MateriaSource::MateriaSource() {
  for (size_t i = 0; i < 4; ++i) {
    templates[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  for (size_t i = 0; i < 4; ++i) {
    delete templates[i];
  }
}

MateriaSource::MateriaSource(MateriaSource const& other) {
  for (int i = 0; i < 4; ++i) {
    templates[i] = NULL;
    if (other.templates[i] != NULL) templates[i] = other.templates[i]->clone();
  }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
  if (this != &other) {
    for (int i = 0; i < 4; ++i) {
      delete templates[i];
      templates[i] = NULL;
      if (other.templates[i] != NULL)
        templates[i] = other.templates[i]->clone();
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* material) {
  if (material == NULL) return;
  for (size_t i = 0; i < 4; ++i) {
    if (templates[i] == NULL) {
      templates[i] = material;
      return;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (size_t i = 0; i < 4; ++i) {
    if (templates[i] && (templates[i]->getType() == type))
      return templates[i]->clone();
  }
  return NULL;
}
