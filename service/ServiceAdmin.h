//
// Created by Sakura on 3/30/2021.
//

#ifndef A45_913ALICEHINCU_SERVICEADMIN_H
#define A45_913ALICEHINCU_SERVICEADMIN_H


#include <string>
#include "../repository/RepositoryShelterDogs.h"

class ServiceAdmin {
private:
    RepositoryShelterDogs& _repo;
public:
    // constructor
    explicit ServiceAdmin(RepositoryShelterDogs& repo);

    // ----------- ADMIN MODE -----------
    // add a dog
    void addDog(const std::string&, const std::string&, int, const std::string&);

    // adopt a dog
    void removeDog(const std::string&);

    // update a dog
    void updateDog(const std::string&, const std::string&, int, const std::string&);

    // return the array of dogs
    DynamicArray<Dog> getShelterDogs();
    // ----------- USER MODE -----------
    // destructor
    ~ServiceAdmin();

    void setCurrentElementIndexServiceAdmin(int nr);

    /*
    //Dog getCurrentDog();
    //void setCurrentDog(const Dog&);


    //void adoptDog();

    //Dog getCurrentElementService();

    //DynamicArray<Dog> getAdoptedDogs();

    //void changeCurrentListService(const DynamicArray<Dog> &newList, bool bl);

    //DynamicArray<Dog> getBreedList(const std::string &breed, int age);
     */
};


#endif //A45_913ALICEHINCU_SERVICEADMIN_H
