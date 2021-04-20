//
// Created by Sakura on 4/20/2021.
//

#include "RepositoryAdoptedDogs.h"

DynamicArray<Dog> RepositoryAdoptedDogs::getAdoptedDogsRepo() {
    return this->_adoptedDogs;
}

void RepositoryAdoptedDogs::addToAdoptedList(const Dog &dog) {
    this->_adoptedDogs.addElement(dog);
}
