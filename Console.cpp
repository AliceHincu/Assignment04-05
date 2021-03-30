//
// Created by Sakura on 3/29/2021.
//

#include <iostream>
#include <limits>
#include "Console.h"
#include "Exceptions.h"


Console::Console(Service& service): _unicorns_exist{true}, _service{service} {}

void Console::run() {
    while (this->_unicorns_exist){
        std::cout << "Choose a mode(administrator/user): ";
        std::string mode;
        std::cin >> mode;
        if (mode == "administrator") {
            this->runAdministrator();
            continue;
        }
        if (mode == "user") {
            this->runUser();
            continue;
        }
        std::cout << "Wrong mode!";
        }

    }


void Console::printMenuAdministrator() {
    std::string menu = "|-----------------------------------|\n"
                       "|   ~ Keep calm and adopt a pet ~   |\n"
                       "|-----------------------------------|\n"
                       "|         1. Add a new dog          |\n"
                       "|         2. Delete a dog           |\n"
                       "|         3. Update a dog           |\n"
                       "|         4. See all dogs           |\n"
                       "|         0. Exit                   |\n"
                       "|-----------------------------------|\n";
    std::cout << menu;

}

void Console::printMenuUser() {

}

void Console::runAdministrator() {
    while (this->_unicorns_exist){
        this->printMenuAdministrator();
        std::cout << ">>> ";
        std::string option;
        std::cin >> option;
        if (option == "0") {
            this->_unicorns_exist = false;
            continue;
        }
        if (option == "1") {
            this->addDogUi();
            continue;
        }
        if (option == "2") {
            std::string name;
            std::cout << "Name: "; std::cin >> name;
            //this->service.removeDog(name);
        }
        if(option == "3"){
            std::string name, photograph;
            int age;
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Age: "; std::cin >> age;
            std::cout << "Photograph: "; std::cin>> photograph;
            //this->service.removeDog(name);
        }
        if(option=="4"){

        }
        else
            std::cout << "\nWrong command!\n";
    }
}

void Console::runUser() {

}

void Console::addDogUi() {
    // input validation
    std::string breed, name, photograph;
    int age;
    std::cout << "Breed: "; std::cin >> breed;
    std::cout << "Name: "; std::cin >> name;

    std::cout << "Age: ";
    while(!(std::cin >> age)){
        std::cout << "Invalid numerical value (age)!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Age: ";
    }

    std::cout << "Photograph: "; std::cin>> photograph;

    try {
        this->_service.addDog(name, breed, age, photograph);
        std::cout << "Dog added!\n";
    }catch(Exceptions &serviceException){
        std::cout << serviceException.get_msg();
    }
}
