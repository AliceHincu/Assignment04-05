#include <iostream>
#include "Console.h"
#include "Tests.h"

int main() {
    Tests t;
    t.runAllTests();

    Repository repository;
    Service service(repository);
    Console console(service);
    console.run();
    return 0;
}
