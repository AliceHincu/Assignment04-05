//
// Created by Sakura on 3/30/2021.
//

#include "RepositoryShelterDogs.h"

RepositoryShelterDogs::RepositoryShelterDogs() = default;

void RepositoryShelterDogs::addDogRepo(const Dog& dog) {
    this->_shelterDogs.addElement(dog);
}

void RepositoryShelterDogs::updateDogRepo(const Dog &dog, int position) {
    this->_shelterDogs.setElement(dog, position);
}

void RepositoryShelterDogs::removeDogRepo(int position) {
    this->_shelterDogs.removeElementFromPosition(position);
}

DynamicArray<Dog> RepositoryShelterDogs::getShelterDogsRepo() {
    return this->_shelterDogs;
}

DynamicArray<Dog> &RepositoryShelterDogs::getShelterDogsRepoUser() {
    return this->_shelterDogs;
}


Dog RepositoryShelterDogs::getCurrentElement() {
    return this->_shelterDogs.getCurrentElement();
}

int RepositoryShelterDogs::getNumberOfDogs() {
    return this->_shelterDogs.getSize();
}

RepositoryShelterDogs::~RepositoryShelterDogs() = default;

//user

void RepositoryShelterDogs::setCurrentElementIndexRepo(int nr) {
    this ->_shelterDogs.setCurrentElementIndex(nr);
}