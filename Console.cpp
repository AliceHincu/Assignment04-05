//
// Created by Sakura on 3/29/2021.
//

#include <iostream>
#include <limits>
#include "Console.h"
#include "Exceptions.h"


Console::Console(ServiceAdmin& serviceAdmin, ServiceUser& serviceUser): _unicorns_exist{true},
        _serviceAdmin{serviceAdmin}, _serviceUser{serviceUser} {}


std::string Console::readString() {
    std::string input;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    return input;
}


void Console::run() {
    this->addTenDogs();
    while (this->_unicorns_exist){
        std::cout << "Choose a mode(administrator/user): ";
        std::string mode;
        mode = readString();
        if (mode == "administrator" or mode == "admin") {
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

// ------------------------ ADMINISTRATOR ---------------------------
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


void Console::runAdministrator() {
    while (this->_unicorns_exist){
        this->printMenuAdministrator();
        std::cout << ">>> ";
        std::string option;
        option = readString();
        if (option == "0") {
            this->_unicorns_exist = false;
            continue;
        }
        if (option == "1") {
            this->addDogUi();
            continue;
        }
        if (option == "2") {
            this->removeDogUi();
            continue;
        }
        if(option == "3"){
            this->updateDogUi();
            continue;
        }
        if(option=="4"){
            this->listDogsUi();
            continue;
        }
        std::cout << "\nWrong command!\n";
    }
}

void Console::addDogUi() {
    // input validation
    std::string breed, name, photograph;
    int age;
    std::cout << "Breed: ";
    breed = readString();
    std::cout << "Name: ";
    name = readString();
    std::cout << "Age: ";
    while(!(std::cin >> age)){
        std::cout << "Invalid numerical value (age)!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Age: ";
    }

    std::cout << "Photograph: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    photograph = readString();

    try {
        this->_serviceAdmin.addDog(name, breed, age, photograph);
        std::cout << "Dog added!\n";
    }catch(Exceptions &serviceAdminException){
        std::cout << serviceAdminException.get_msg();
    }
}


void Console::removeDogUi() {
    std::string name;
    std::cout << "Name of the existing dog: ";
    name = readString();

    try {
        this->_serviceAdmin.removeDog(name);
        std::cout << "Yaaay it got adopted o(^_^)o!!!! \n";
    }catch(Exceptions &serviceAdminException){
        std::cout << serviceAdminException.get_msg();
    }
}

void Console::updateDogUi() {
    // input validation
    std::string breed, name, photograph;
    int age;
    std::cout << "Name of the existing dog: "; std::cin >> name;

    std::cout << "New Breed: "; std::cin >> breed;

    std::cout << "New Age: ";
    while(!(std::cin >> age)){
        std::cout << "Invalid numerical value (age)!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "New Age: ";
    }

    std::cout << "New Photograph: "; std::cin>> photograph;

    try {
        this->_serviceAdmin.updateDog(name, breed, age, photograph);
        std::cout << "Dog updated!\n";
    }catch(Exceptions &serviceAdminException){
        std::cout << serviceAdminException.get_msg();
    }
}


void Console::listDogsUi() {
    auto dogs = this->_serviceAdmin.getShelterDogs();
    int numberOfDogs = dogs.getSize();
    dogs.setCurrentElementIndex(0);
    for (int i=0; i<numberOfDogs; i++) {
        std::cout << dogs.getCurrentElement();
    }
}

void Console::addTenDogs() {
    this->_serviceAdmin.addDog("Brutus", "Street dog", 4,
                          "https://post.medicalnewstoday.com/wp-content/uploads/sites/3/2020/02/322868_1100-800x825.jpg");
    this->_serviceAdmin.addDog("Princess", "Beagle", 2,
                          "https://www.publicdomainpictures.net/pictures/250000/velka/dog-beagle-portrait.jpg");
    this->_serviceAdmin.addDog("Zack", "Golden Retriever", 1,
                          "https://i.pinimg.com/originals/95/77/3a/95773a62497aadf957fb800b99dae301.jpg");
    this->_serviceAdmin.addDog("Cody", "Golden Retriever", 1,
                          "https://cdn.pixabay.com/photo/2017/09/02/08/54/golden-retriever-puppy-2706681_1280.jpg");
    this->_serviceAdmin.addDog("Kara", "Street dog", 3,
                          "https://learnenglishteens.britishcouncil.org/sites/teens/files/styles/article/public/rs7320_thinkstockphotos-492514064-low.jpg?itok=wtQWVBJB");
    this->_serviceAdmin.addDog("Nala", "Street dog", 6,
                          "https://media.4-paws.org/2/1/f/2/21f2e1c51bedd0a4315cf9b234a17075150c711e/VIER%20PFOTEN_2014-09-09_025-3330x2304-1300x899.jpg");
    this->_serviceAdmin.addDog("Otto", "Bichon Maltese", 5,
                          "https://rasedecaini.ro/wp-content/uploads/2019/05/rasa-bichon-maltez.jpg");
    this->_serviceAdmin.addDog("Norman", "Yorkshire Terrier", 1,
                          "https://i.pinimg.com/originals/ca/32/44/ca3244addedf3b1e9fd0d90629bc339e.jpg");
    this->_serviceAdmin.addDog("Daisy", "Pitbull", 10,
                          "https://www.cutzucutzu.com/wp-content/uploads/2019/06/pitbull-cea-mai-buna-hrana-2-1024x683.jpg");
    this->_serviceAdmin.addDog("Bella", "Street dog", 7,
                          "https://i.redd.it/2qzcwkya6fl11.jpg");
}

Console::~Console() = default;

/*

void Console::printMenuUserChooseList(){
    std::string menu = "|-----------------------------------|\n"
                       "|   ~ Keep calm and adopt a pet ~   |\n"
                       "|-----------------------------------|\n"
                       "|1.See all the dogs                 |\n"
                       "|2.See all the dogs of a given breed|\n"
                       "|0.Exit                             |\n"
                       "|-----------------------------------|\n";
    std::cout << menu;
}

}
void Console::runUserChooseList() {
    while (this->_unicorns_exist){
        this->printMenuUserChooseList();
        std::cout << ">>> ";
        std::string option;
        std::cin >> option;
        if (option == "0") {
            this->_unicorns_exist = false;
            continue;
        }
        if (option == "1") {
            this->_serviceAdmin.changeCurrentListserviceAdmin(this->_serviceAdmin.getDogs(), true);
            this->runUser();
            continue;
        }
        if (option == "2") {
            std::cout << "See all the dogs of a given breed, having an age less than a given number. If no breed is"
                         " provided, then all the dogs will be considered. The functionalities outlined above apply "
                         "again in this case.\n";
            std::cout << "Input breed: ";
            std::string breed;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            breed = readString();
            int age;
            std::cout << "Age: ";
            while(!(std::cin >> age)){
                std::cout << "Invalid numerical value (age)!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Age: ";
            }
            DynamicArray<Dog> breedList = this->_serviceAdmin.getBreedList(breed, age);

            this->_serviceAdmin.changeCurrentListserviceAdmin(breedList, false);
            this->runUser();
            continue;
        }

        std::cout << "\nWrong command!\n";
    }
}*/

void Console::runUser() {
    this->printMenuUser();
    this->_serviceAdmin.setCurrentElementIndexServiceAdmin(0);
    bool isInFilteredList = false;
    auto currentList = this->_serviceUser.getShelterDogs();
    while (this->_unicorns_exist){
        std::cout << ">>> ";
        std::string option;
        std::cin >> option;
        if (option == "0") {
            this->_unicorns_exist = false;
            continue;
        }
        if (option == "1") {
            this->userShowDogUi(this->_serviceUser.getShelterDogs());
            continue;
        }
        if (option == "2") {
            this->userAdoptDogUi(this->_serviceUser.getShelterDogs());
            continue;
        }
        if(option == "3"){
            this->UserNextDogUi(this->_serviceUser.getShelterDogs());
            continue;
        }
        if(option == "4"){
            this->userAdoptionListUi();
            continue;
        }
        if(option == "5") {
            DynamicArray<Dog> filteredList = this->sortByBreedUi();
            bool filtered = true;
            while(filtered) {
                std::cout << ">>> ";
                std::string option;
                std::cin >> option;
                if (option == "0") {
                    this->_serviceUser.setCurrentElementIndexService(0);
                    filtered = false;
                    continue;
                }
                if (option == "1") {
                    this->userShowDogUi(filteredList);
                    continue;
                }
                if (option == "2") {
                    this->userAdoptDogUiFiltered(filteredList);
                    continue;
                }
                if (option == "3") {
                    this->UserNextDogUi(filteredList);
                    continue;
                }
                if (option == "4") {
                    this->userAdoptionListUi();
                    continue;
                }
            }
        }
        std::cout << "\nWrong command!\n";
    }
}


void Console::printMenuUser() {
    std::string menu = "|-----------------------------------|\n"
                       "|   ~ Keep calm and adopt a pet ~   |\n"
                       "|-----------------------------------|\n"
                       "|         1. See the dogs           |\n"
                       "|         2. Adopt the dog          |\n"
                       "|         3. Don't adopt            |\n"
                       "|         4. See adoption list      |\n"
                       "|         0. Exit                   |\n"
                       "|-----------------------------------|\n";
    std::cout << menu;
}

void Console::userShowDogUi(DynamicArray<Dog> dogs) {
    if (dogs.getSize() == 0){
        std::cout << "\nAll dogs got adopted yaay!!!\n";
        return;
    }
    std::cout << "\nCurrent dog:\n";
    Dog dog = dogs.getCurrentElement();  // get the current dog
    std::cout << dog;
}

void Console::userAdoptDogUi(const DynamicArray<Dog>& dogs) {
    if (dogs.getSize() == 0){
        std::cout << "\nAll dogs got adopted yaay!!!\n";
        return;
    }
    this->_serviceUser.adoptDogShelter(dogs);
    std::cout << "Dog adopted!\n"; //then go the next dog
}

void Console::userAdoptionListUi() {
    if (this->_serviceUser.getShelterDogs().getSize() == 0) {
        std::cout << "\nAll dogs got adopted yaay!!!\n";
        return;
    }
    auto dogs = this->_serviceUser.getAdoptedDogs();  //get dogs
    int numberOfDogs = dogs.getSize();
    dogs.setCurrentElementIndex(0);
    for (int i = 0; i < numberOfDogs; i++) {
        std::cout << dogs.getCurrentElement();
    }
}

void Console::userAdoptDogUiFiltered(DynamicArray<Dog>& dogs) {
    if (dogs.getSize() == 0){
        std::cout << "\nAll dogs got adopted yaay!!!\n";
        return;
    }
    //this->_serviceUser.adoptDogShelter(this->_serviceUser.getShelterDogs());
    this->_serviceUser.adoptDogFiltered(dogs);
    std::cout << "Dog adopted!\n"; //then go the next dog
}


void Console::UserNextDogUi(DynamicArray<Dog> &dogs) {
    if (dogs.getSize() == 0){
        std::cout << "\nAll dogs got adopted yaay!!!\n";
        return;
    }
    std::cout << "\nNext dog:\n";
    Dog dog = dogs.getCurrentElement();
    int index = dogs.getCurrentElementIndex(); // get the next index
    dog = dogs.getCurrentElement();
    std::cout << dog;
    dogs.setCurrentElementIndex(index);
    }

DynamicArray<Dog> Console::sortByBreedUi() {
    std::cout << "See all the dogs of a given breed, having an age less than a given number. If no breed is"
                 " provided, then all the dogs will be considered. The functionalities outlined above apply "
                 "again in this case.\n";
    std::cout << "Input breed: ";
    std::string breed;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    breed = readString();
    int age;
    std::cout << "Age: ";
    while(!(std::cin >> age)){
        std::cout << "Invalid numerical value (age)!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Age: ";
    }

    auto filteredList = this->_serviceUser.getFilteredDogs(breed, age);
    return filteredList;
}

