// Subject-mandated usage scenario.
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");
  AMateria* tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);

  // Deep-copy and unequip ownership checks. Character retains unequipped
  // Materias in its floor list and deletes them in its destructor.
  Character original("original");
  original.equip(src->createMateria("ice"));
  Character copied(original);
  Character assigned("assigned");
  assigned = original;
  original.unequip(0);
  Character floor_copy(original);
  Character floor_assigned("floor-assigned");
  floor_assigned = original;

  // MateriaSource copies must own independent template clones.
  MateriaSource source_copy;
  source_copy.learnMateria(new Ice());
  MateriaSource assigned_source;
  assigned_source = source_copy;
  AMateria* copied_materia = assigned_source.createMateria("ice");
  delete copied_materia;

  delete bob;
  delete me;
  delete src;
  return 0;
}
