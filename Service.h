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
    Service(Repository& repo);
    void addDog(const std::string&, const std::string&, int, const std::string&);
};


#endif //A45_913ALICEHINCU_SERVICE_H
