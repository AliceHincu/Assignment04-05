//
// Created by Sakura on 3/30/2021.
//

#ifndef A45_913ALICEHINCU_REPOSITORYSHELTERDOGS_H
#define A45_913ALICEHINCU_REPOSITORYSHELTERDOGS_H


#include "../Dog.h"
#include "../DynamicArray.h"

class RepositoryShelterDogs {
private:
    DynamicArray<Dog> _shelterDogs{10};
    //DynamicArray<Dog> _adopted{10};
    //DynamicArray<Dog> _current_list = _elems;
    //bool bigList = true;
    //Dog currentDog;
public:
    // constructor
    RepositoryShelterDogs();

    // ----------- ADMIN MODE -----------
    void addDogRepo(const Dog&);
    void removeDogRepo(int);
    void updateDogRepo(const Dog&, int);
    DynamicArray<Dog> getShelterDogsRepo();
    DynamicArray<Dog> &getShelterDogsRepoUser();

    // ----------- USER MODE -----------
    //Dog getCurrentDogRepo();
    //void setCurrentDogRepo(const Dog&);
    // ----------- FROM DYNAMIC ARRAY-----------
    Dog getCurrentElement();
    int getNumberOfDogs();

    // destructor
    ~RepositoryShelterDogs();

    void setCurrentElementIndexRepo(int);

    //void addAdoptedDogRepo(const Dog &dog);

    //DynamicArray<Dog> getAdoptedDogsRepo();

    //void changeCurrentListRepo(const DynamicArray<Dog> &newList, bool);
};



#endif //A45_913ALICEHINCU_REPOSITORYSHELTERDOGS_H
