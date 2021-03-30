//
// Created by Sakura on 3/30/2021.
//

#include "Service.h"
#include "Exceptions.h"

Service::Service(Repository& repo): _repo{repo} {}

void Service::addDog(const std::string &name, const std::string &breed, int age, const std::string &photograph) {
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


void Service::removeDog(const std::string &name) {
    // validate
    int numberOfDogs = this->_repo.getNumberOfDogs();
    int position = -1;
    int isExisting = false;
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

DynamicArray<Dog> Service::getDogs() {
    return this->_repo.getDogsRepo();

}

void Service::updateDog(const std::string& name, const std::string& newBreed, int newAge, const std::string& newPhoto) {
    // validate
    int numberOfDogs = this->_repo.getNumberOfDogs();
    int position = -1;
    int isExisting = false;
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

Service::~Service() = default;
