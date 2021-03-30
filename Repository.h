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
    Repository();

    void addDogRepo(const Dog&);
    DynamicArray<Dog> getDogs();
    Dog getCurrentElement();
    int getNumberOfDogs();

    ~Repository();
    };



#endif //A45_913ALICEHINCU_REPOSITORY_H
