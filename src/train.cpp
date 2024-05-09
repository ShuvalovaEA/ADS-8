// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool light) {
    Cage* node = new Cage;
    node->light = light;
    if (first == nullptr) {
        first = node;
        first->prev = node;
        first->next = node;
    } else {
        node->prev = first;
        node->next = first->next;
        first->next->prev = node;
        first->next = node;
    }
}

int Train::getLength() {
    Cage *current = first;
    int length = 0;
    while (current != nullptr) {
        current = current->next;
        length++;
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}
