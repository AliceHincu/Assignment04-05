//
// Created by Sakura on 3/29/2021.
//

#ifndef A45_913ALICEHINCU_CONSOLE_H
#define A45_913ALICEHINCU_CONSOLE_H


#include "Service.h"

class Console {
private:
    bool _unicorns_exist = true;

    Service& _service;

    static void printMenuAdministrator();

    void printMenuUser();

    void runAdministrator();

    void runUser();

    void addDogUi();
public:
    //implicit constructor;
    Console(Service& service);

    void run();
};


#endif //A45_913ALICEHINCU_CONSOLE_H
