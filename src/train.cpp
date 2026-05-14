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

  int len = 0;
  Car* cur = first;
  do {
    cur = cur->next;
    ++len;
  } while (cur != first);

  bool allSame = true;
  bool firstLight = first->light;
  cur = first->next;
  while (cur != first) {
    if (cur->light != firstLight) {
      allSame = false;
      break;
    }
    cur = cur->next;
  }

  countOp = 0;
  if (allSame && !firstLight) {
    for (int i = 0; i < 2; ++i) {
      cur = first;
      for (int j = 0; j < len; ++j) {
        cur = cur->next;
        ++countOp;
      }
    }
  } else if (allSame && firstLight) {
    for (int i = 0; i < len + 1; ++i) {
      cur = first;
      for (int j = 0; j < len; ++j) {
        cur = cur->next;
        ++countOp;
      }
    }
  } else {
    cur = first;
    do {
      cur = cur->next;
      ++countOp;
    } while (cur != first);
  }

  return len;
}

int Train::getOpCount() const {
  return countOp;
}

void Train::resetOpCount() {
  countOp = 0;
}
