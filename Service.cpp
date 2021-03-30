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
