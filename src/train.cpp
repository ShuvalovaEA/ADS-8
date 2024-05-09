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
    Cage* temp = first;
    first = new Cage;
    first->prev = temp;
    first->next = temp->next;
    first->next->prev = first;
    first->light = light;
    length++;
}

int Train::getLength() {
    return length;
}

int Train::getOpCount() {
    return countOp;
}
