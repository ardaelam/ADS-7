// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
  if (!first) return;
  Car* current = first->next;
  while (current != first) {
    Car* toDelete = current;
    current = current->next;
    delete toDelete;
  }
  delete first;
}

void Train::addCar(bool light) {
  Car* newCar = new Car(light);
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  Car* current = first;
  do {
    current = current->next;
    ++countOp;
  } while (current != first);
  return countOp;
}

int Train::getOpCount() const {
  return countOp;
}

void Train::resetOpCount() {
  countOp = 0;
}
