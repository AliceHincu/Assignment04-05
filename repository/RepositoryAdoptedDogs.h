//
// Created by Sakura on 4/20/2021.
//

#ifndef A45_913ALICEHINCU_REPOSITORYADOPTEDDOGS_H
#define A45_913ALICEHINCU_REPOSITORYADOPTEDDOGS_H


#include "../Dog.h"
#include "../DynamicArray.h"

class RepositoryAdoptedDogs {
private:
    DynamicArray<Dog> _adoptedDogs{10};
public:
    DynamicArray<Dog> getAdoptedDogsRepo();
    void addToAdoptedList(const Dog&);
};


#endif //A45_913ALICEHINCU_REPOSITORYADOPTEDDOGS_H
