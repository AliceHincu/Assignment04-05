//
// Created by Sakura on 4/19/2021.
//

#include "ServiceUser.h"

ServiceUser::ServiceUser(RepositoryShelterDogs &repoShelter, RepositoryAdoptedDogs &repoAdopted):
    _repoShelter{repoShelter}, _repoAdopted{repoAdopted} {}

DynamicArray<Dog> &ServiceUser::getShelterDogs() {
    return this->_repoShelter.getShelterDogsRepoUser();
}

DynamicArray<Dog> ServiceUser::getAdoptedDogs() {
    return this->_repoAdopted.getAdoptedDogsRepo();
}

void ServiceUser::removeDogShelter(const std::string &name) {
    // validate
    int numberOfDogs = this->_repoShelter.getNumberOfDogs();
    int position = -1;
    int isExisting = false;
    this->_repoShelter.setCurrentElementIndexRepo(0);
    for (int i=0; i<numberOfDogs; i++) {
        Dog existingDog = this->_repoShelter.getCurrentElement();
        if (name == existingDog.get_name()) {
            position = i;
            isExisting = true;
        }
    }

    if (isExisting == false)
        std::cout << "Dog does not exist!\n\n";

    // remove the dog
    this->_repoShelter.removeDogRepo(position);
}


void ServiceUser::adoptDogShelter(DynamicArray<Dog> dogs) {
    int index = dogs.getCurrentElementIndex();
    Dog dog = dogs.getCurrentElement();
    this->removeDogShelter(dog.get_name());
    this->_repoAdopted.addToAdoptedList(dog);
    this->_repoShelter.setCurrentElementIndexRepo(index);

}

void ServiceUser::setCurrentElementIndexService(int i) {
    this->_repoShelter.setCurrentElementIndexRepo(i);
}

DynamicArray<Dog> ServiceUser::getFilteredDogs(const std::string &breed, int age){
    auto dogs = this->getShelterDogs();
    DynamicArray<Dog>dogsBreed{10};
    if (breed != ""){
        int numberOfDogs = dogs.getSize();
        dogs.setCurrentElementIndex(0);
        for (int i=0; i<numberOfDogs; i++) {
            Dog dog = dogs.getCurrentElement();
            if (dog.get_breed()==breed and dog.get_age() < age)
                dogsBreed.addElement(dog);
        }
    }else{
        int numberOfDogs = dogs.getSize();
        dogs.setCurrentElementIndex(0);
        for (int i=0; i<numberOfDogs; i++) {
            Dog dog = dogs.getCurrentElement();
            if (dog.get_age() < age)
                dogsBreed.addElement(dog);
        }
    }

    return dogsBreed;

}

void ServiceUser::adoptDogFiltered(DynamicArray<Dog> &dogs) {
    int index = dogs.getCurrentElementIndex();
    Dog dog = dogs.getCurrentElement();
    //this->removeDogShelter(dog.get_name());
    int numberOfDogs = dogs.getSize();
    int position = -1;
    int isExisting = false;
    dogs.setCurrentElementIndex(0);
    for (int i=0; i<numberOfDogs; i++) {
        Dog existingDog = dogs.getCurrentElement();
        if (dog.get_name() == existingDog.get_name()) {
            position = i;
            isExisting = true;
        }
    }

    if (isExisting == false)
        std::cout << "Dog does not exist!\n\n";

    // remove the dog
    dogs.removeElementFromPosition(position);
    this->removeDogShelter(dog.get_name());

    this->_repoAdopted.addToAdoptedList(dog);
    dogs.setCurrentElementIndex(index);
}

/*
DynamicArray<Dog> ServiceUser::getFilteredDogs() {
    //return DynamicArray<Dog>();

}*/
