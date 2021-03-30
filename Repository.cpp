//
// Created by Sakura on 3/30/2021.
//

#include "Repository.h"

Repository::Repository() {}

void Repository::addDogRepo(const Dog& dog) {
    this->_elems.addElement(dog);
}

void Repository::updateDogRepo(const Dog &dog, int position) {
    this->_elems.setElement(dog, position);
}

void Repository::removeDogRepo(int position) {
    this->_elems.removeElementFromPosition(position);
}

DynamicArray<Dog> Repository::getDogsRepo() {
    return this->_elems;
}

Dog Repository::getCurrentElement() {
    return this->_elems.getCurrentElement();
}

int Repository::getNumberOfDogs() {
    return this->_elems.getSize();
}

Repository::~Repository() {}

