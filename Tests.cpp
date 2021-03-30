//
// Created by Sakura on 3/30/2021.
//

#include <iostream>
#include <cassert>
#include "Tests.h"
#include "Dog.h"
#include "Service.h"
#include "Exceptions.h"


void Tests::runAllTests() {
    std::cout << "Starting tests...\n";
    this->run_domain_tests();
    this->run_validation_tests();
    this->runServiceTests();
    std::cout << "Finishing tests...\n";
}

void Tests::runServiceTests() {
    std::cout << "Starting service admin tests...\n";

    Repository repo;
    Service service(repo);

    // add a dog function
    service.addDog("Hera", "Yorkshire Terrier", 6, "link");
    try {
        service.addDog("Hera", "Yorkshire Terrier", 4, "link2");
        assert(false);
    }catch(const Exceptions& serviceException){
        assert(serviceException.get_msg()=="Dog already exists!\n\n");
    }

    // remove a dog function
    try {
        service.removeDog("laa");
        assert(false);
    }catch(const Exceptions& serviceException){
        assert(serviceException.get_msg()=="Dog does not exist!\n\n");
    }
    service.removeDog("Hera");
    assert(service.getDogs().getSize() == 0);

    // update a dog function
    service.addDog("Hera", "Yorkshire Terrier", 6, "link");
    try {
        service.updateDog("laa",  "Yorkshire Terrier", 6, "link");
        assert(false);
    }catch(const Exceptions& serviceException){
        assert(serviceException.get_msg()=="Dog does not exist!\n\n");
    }
    service.updateDog("Hera", "blaa", 3, "link3");
    int age = service.getDogs().getCurrentElement().get_age();
    std::string breed = service.getDogs().getCurrentElement().get_breed();
    std::string photo = service.getDogs().getCurrentElement().get_photograph();
    assert(age == 3);
    assert(breed == "blaa");
    assert(photo == "link3");

    std::cout << "Finishing service admin tests...\n";
}

void Tests::run_domain_tests() {
    std::cout << "Starting domain tests...\n";
    // implicit constructor
    Dog d;
    assert(d.get_name()=="");
    assert(d.get_age()==-1);
    assert(d.get_breed()=="");
    assert(d.get_photograph()=="");

    // explicit constructor
    Dog d1("Hera", "Yorkshire Terrier", 6, "link");
    assert(d1.get_name()=="Hera");
    assert(d1.get_breed()=="Yorkshire Terrier");
    assert(d1.get_age()==6);
    assert(d1.get_photograph()=="link");

    // copy constructor;
    Dog d2{d1};
    d2.set_age(8);
    d2.set_photograph("link2");
    assert(d2.get_age() == 8);
    assert(d2.get_photograph() == "link2");

    // check if d3 remains the same
    Dog d3 = d1;
    d1.set_age(3);
    assert(d3.get_age() == 6);

    // check = operator
    Dog d4;
    d4 = d3;
    assert(d4.get_age() == 6);

    // check == operator
    assert(d4 == d3);

    /*
    Dog d5;
    std::cin >> d5;
    std::cout << d5;
    */

    std::cout << "Finishing domain tests...\n";
}

void Tests::run_validation_tests() {
    /*
    std::cout << "Starting validation tests...\n";
    2, c{23, "Jaguar", 7869.5};
    CarValidator::validate(c);

    Car c1{23, "", -7869.5};
    try {
        CarValidator::validate(c1);
        assert(false);
    }catch(const ValidationException& ve){
        assert(ve.get_msg()=="Invalid name!\nInvalid price!\n");

    }
    std::cout << "Finishing validation tests...\n";
    */
}
