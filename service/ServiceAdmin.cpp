//
// Created by Sakura on 3/30/2021.
//

#include "ServiceAdmin.h"
#include "../Exceptions.h"

ServiceAdmin::ServiceAdmin(RepositoryShelterDogs& repo): _repo{repo} {}

void ServiceAdmin::addDog(const std::string &name, const std::string &breed, int age, const std::string &photograph) {
    // create the dog
    Dog dog{name, breed, age, photograph};

    // validate
    int numberOfDogs = this->_repo.getNumberOfDogs();
    for (int i=0; i<numberOfDogs; i++) {
        Dog existingDog = this->_repo.getCurrentElement();
        if (dog == existingDog) {
            throw Exceptions("Dog already exists!\n\n");
        }
    }

    // add the dog
    this->_repo.addDogRepo(dog);

}


void ServiceAdmin::removeDog(const std::string &name) {
    // validate
    int numberOfDogs = this->_repo.getNumberOfDogs();
    int position = -1;
    int isExisting = false;
    this->_repo.setCurrentElementIndexRepo(0);
    for (int i=0; i<numberOfDogs; i++) {
        Dog existingDog = this->_repo.getCurrentElement();
        if (name == existingDog.get_name()) {
            position = i;
            isExisting = true;
        }
    }

    if (isExisting == false)
        throw Exceptions("Dog does not exist!\n\n");

    // remove the dog
    this->_repo.removeDogRepo(position);
}

DynamicArray<Dog> ServiceAdmin::getShelterDogs() {
    return this->_repo.getShelterDogsRepo();

}
void ServiceAdmin::updateDog(const std::string& name, const std::string& newBreed, int newAge, const std::string& newPhoto) {
    // validate
    int numberOfDogs = this->_repo.getNumberOfDogs();
    int position = -1;
    int isExisting = false;
    this->_repo.setCurrentElementIndexRepo(0);
    for (int i=0; i<numberOfDogs; i++) {
        Dog existingDog = this->_repo.getCurrentElement();
        if (name == existingDog.get_name()) {
            position = i;
            isExisting = true;
        }
    }

    if (isExisting == false)
        throw Exceptions("Dog does not exist!\n\n");

    // update the dog
    Dog dog{name, newBreed, newAge, newPhoto};
    this->_repo.updateDogRepo(dog, position);
}


void ServiceAdmin::setCurrentElementIndexServiceAdmin(int nr) {
    this->_repo.setCurrentElementIndexRepo(nr);
}

/*
void ServiceAdmin::changeCurrentListService(const DynamicArray<Dog>& newList, bool bl){
    this->_repo.changeCurrentListRepo(newList, bl);
}


*/
ServiceAdmin::~ServiceAdmin() = default;
