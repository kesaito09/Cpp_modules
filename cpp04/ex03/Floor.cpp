#include "Floor.hpp"

#include "AMateria.hpp"

Floor::Floor() : head_(NULL) {}

Floor::Floor(Floor const& other) : head_(NULL) { copyFrom(other); }

Floor::~Floor() { clear(); }

Floor& Floor::operator=(Floor const& other) {
  if (this != &other) {
    clear();
    copyFrom(other);
  }
  return *this;
}

void Floor::drop(AMateria* materia) {
  Node* node = new Node;
  node->materia = materia;
  node->next = head_;
  head_ = node;
}

void Floor::clear() {
  while (head_ != NULL) {
    Node* node = head_;
    head_ = head_->next;
    delete node->materia;
    delete node;
  }
}

void Floor::copyFrom(Floor const& other) {
  for (Node const* node = other.head_; node != NULL; node = node->next)
    drop(node->materia->clone());
}
