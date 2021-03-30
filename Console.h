//
// Created by Sakura on 3/29/2021.
//

#ifndef A45_913ALICEHINCU_CONSOLE_H
#define A45_913ALICEHINCU_CONSOLE_H


#include "Service.h"

class Console {
private:
    // for the while loop
    bool _unicorns_exist = true;

    // the service
    Service& _service;

    // menu admin
    static void printMenuAdministrator();

    // menu user
    void printMenuUser();

    // run the loop for admin mode
    void runAdministrator();

    // run the loop for user mode
    void runUser();

    // ----------- ADMIN MODE -----------
    void addDogUi();

    void removeDogUi();

    void listDogsUi();

    void updateDogUi();

    // ----------- USER MODE -----------
public:
    // constructor;
    explicit Console(Service& service);

    // main loop;
    void run();

    // destructor
    ~Console();
};


#endif //A45_913ALICEHINCU_CONSOLE_H
