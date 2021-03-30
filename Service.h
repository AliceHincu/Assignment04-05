//
// Created by Sakura on 3/30/2021.
//

#ifndef A45_913ALICEHINCU_SERVICE_H
#define A45_913ALICEHINCU_SERVICE_H


#include <string>
#include "Repository.h"

class Service {
private:
    Repository& _repo;
public:
    // constructor
    explicit Service(Repository& repo);

    // ----------- ADMIN MODE -----------
    // add a dog
    void addDog(const std::string&, const std::string&, int, const std::string&);

    // adopt a dog
    void removeDog(const std::string&);

    // update a dog
    void updateDog(const std::string&, const std::string&, int, const std::string&);

    // return the array of dogs
    DynamicArray<Dog> getDogs();
    // ----------- USER MODE -----------

    // destructor
    ~Service();

};


#endif //A45_913ALICEHINCU_SERVICE_H
