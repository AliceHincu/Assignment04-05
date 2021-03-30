//
// Created by Sakura on 3/30/2021.
//

#include "Dog.h"

Dog::Dog(): _name{""}, _breed{""}, _age{-1}, _photograph{""} {}


Dog::Dog(const std::string &name, const std::string &breed, int age, const std::string &photograph):
_breed{breed}, _name{name}, _age{age}, _photograph{photograph}{}


Dog::Dog(const Dog &d): _breed{d._breed}, _name{d._name}, _age{d._age}, _photograph{d._photograph} {}

Dog &Dog::operator=(const Dog &other) {
    this->_name = other._name;
    this->_breed = other._breed;
    this->_age = other._age;
    this->_photograph = other._photograph;
    return *this;
}

bool Dog::operator==(const Dog &other) const {
    return this->_name == other._name;
}

std::ostream &operator<<(std::ostream &os, const Dog &d) {
    os << "-------------- Doggy --------------\n";
    os << "Name: " << d._name << "\nBreed: " << d._breed << "\nAge: " << d._age << "\nPhoto: " << d._photograph << "\n";
    os << "-----------------------------------\n";
    return os;
}

std::istream &operator>>(std::istream &is, Dog &d) {
    std::cout << "Name: "; is >> d._name;
    std::cout << "Breed: "; is >> d._breed;
    std::cout << "Age: "; is >> d._age;
    std::cout << "Photo: "; is >> d._photograph;
    return is;
}

int Dog::get_age() const {
    return this->_age;
}

const std::string &Dog::get_name() const {
    return this->_name;
}

const std::string &Dog::get_breed() const {
    return this->_breed;
}

const std::string &Dog::get_photograph() const {
    return this->_photograph;
}

void Dog::set_photograph(const std::string &photo) {
    this->_photograph = photo;
}

void Dog::set_age(int age) {
    this->_age = age;
}

Dog::~Dog() {

}
