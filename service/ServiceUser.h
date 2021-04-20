//
// Created by Sakura on 4/19/2021.
//

#ifndef A45_913ALICEHINCU_SERVICEUSER_H
#define A45_913ALICEHINCU_SERVICEUSER_H


#include "../repository/RepositoryShelterDogs.h"
#include "../repository/RepositoryAdoptedDogs.h"

class ServiceUser {
private:
    RepositoryShelterDogs& _repoShelter;
    RepositoryAdoptedDogs& _repoAdopted;
    //Dog _currentDog{};
public:
    // constructor
    explicit ServiceUser(RepositoryShelterDogs&, RepositoryAdoptedDogs&);

    // return the array of dogs
    DynamicArray<Dog>& getShelterDogs();
    DynamicArray<Dog> getAdoptedDogs();
    DynamicArray<Dog> getFilteredDogs(const std::string& breed, int age);

    void adoptDogShelter(DynamicArray<Dog>);

    void removeDog(const std::string &name);

    void removeDogShelter(const std::string &name);

    Dog getNextDog(DynamicArray<Dog> &);

    void setCurrentElementIndexService(int i);

    void adoptDogFiltered(DynamicArray<Dog> &);

    void removeDogShelterFilter(DynamicArray<Dog> &dogs);
};


#endif //A45_913ALICEHINCU_SERVICEUSER_H
