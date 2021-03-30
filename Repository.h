//
// Created by Sakura on 3/30/2021.
//

#ifndef A45_913ALICEHINCU_REPOSITORY_H
#define A45_913ALICEHINCU_REPOSITORY_H


#include "Dog.h"
#include "DynamicArray.h"

class Repository {
private:
    DynamicArray<Dog> _elems{10};
public:
    // constructor
    Repository();

    // ----------- ADMIN MODE -----------
    void addDogRepo(const Dog&);
    void removeDogRepo(int);
    void updateDogRepo(const Dog&, int);
    DynamicArray<Dog> getDogsRepo();

    // ----------- USER MODE -----------

    // ----------- FROM DYNAMIC ARRAY-----------
    Dog getCurrentElement();
    int getNumberOfDogs();

    // destructor
    ~Repository();
    };



#endif //A45_913ALICEHINCU_REPOSITORY_H
