//
// Created by Sakura on 3/29/2021.
//

#ifndef A45_913ALICEHINCU_CONSOLE_H
#define A45_913ALICEHINCU_CONSOLE_H


#include "service/ServiceAdmin.h"
#include "service/ServiceUser.h"

class Console {
private:

// for the while loop
    bool _unicorns_exist = true;

    // the services
    ServiceAdmin& _serviceAdmin;
    ServiceUser& _serviceUser;

    // for reading string with spaces
    std::string readString();

    // menu admin
    static void printMenuAdministrator();

    // menu user
    void printMenuUser();

    // run the loop for admin mode
    void runAdministrator();

    void runUser();

    // run the loop for user mode
    //void runUser();

    // add 10 inputs
    void addTenDogs();

    // ----------- ADMIN MODE -----------
    void addDogUi();

    void removeDogUi();

    void listDogsUi();

    void updateDogUi();

    // ----------- USER MODE -----------
    // show current dog
    void userShowDogUi(DynamicArray<Dog>);

    void userAdoptDogUi(const DynamicArray<Dog>&);

    void userAdoptionListUi();

    void UserNextDogUi(DynamicArray<Dog>&);

    DynamicArray<Dog> sortByBreedUi();


public:
    // constructor;
    Console(ServiceAdmin &serviceAdmin, ServiceUser &serviceUser);

    // main loop;
    void run();

    // destructor
    ~Console();
/*
    void userListDogsUi();

    void runUser();

    void userAdoptDogUi();

    void userAdoptionListUi();

    void UserNotAdoptDogUi();

    void printMenuUserChooseList();

    void runUserChooseList();*/
    void userAdoptDogUiFiltered(DynamicArray<Dog> &dogs);
};


#endif //A45_913ALICEHINCU_CONSOLE_H
