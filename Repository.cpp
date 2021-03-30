//
// Created by Sakura on 3/30/2021.
//

#include "Repository.h"

Repository::Repository() {}

void Repository::addDogRepo(const Dog& dog) {
    this->_elems.addElement(dog);
}

Repository::~Repository() {}

DynamicArray<Dog> Repository::getDogs() {
    return this->_elems;
}

Dog Repository::getCurrentElement() {
    return this->_elems.getCurrentElement();
}

int Repository::getNumberOfDogs() {
    return this->_elems.getSize();
}
