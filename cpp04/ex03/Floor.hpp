#ifndef FLOOR_HPP
#define FLOOR_HPP

class AMateria;

class Floor {
 private:
  struct Node {
    AMateria* materia;
    Node* next;
  };

  Node* head_;

  void clear();
  void copyFrom(Floor const& other);

 public:
  Floor();
  Floor(Floor const& other);
  ~Floor();
  Floor& operator=(Floor const& other);

  void drop(AMateria* materia);
};

#endif
