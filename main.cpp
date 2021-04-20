#include <iostream>
#include "Console.h"
#include "Tests.h"
#include "repository/RepositoryAdoptedDogs.h"

int main() {
    //Tests t;
    //t.runAllTests();
    RepositoryShelterDogs repoShelter;
    RepositoryAdoptedDogs repoAdopted;
    ServiceAdmin serviceAdmin(repoShelter);
    ServiceUser serviceUser(repoShelter, repoAdopted);
    Console console(serviceAdmin, serviceUser);
    console.run();

    return 0;
}
