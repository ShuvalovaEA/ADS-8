// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = new Cage;
    first->prev = nullptr;
    first->light = false;
    first->next = first;
    countOp = 0;
    length = 0;
}

void Train::addCage(bool light) {
    if (first == nullptr) {
        first = new Cage{light, nullptr, nullptr};
    } else {
        Cage* temp = first;
        first = new Cage{light, first, nullptr};
        first->next->prev = first;
        first->next = temp;
        temp->prev = first;
    }
    length++;
}

int Train::getLength() {
    return length;
}

int Train::getOpCount() {
    return countOp;
}
