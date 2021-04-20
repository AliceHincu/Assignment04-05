cmake_minimum_required(VERSION 3.19)
project(a45_913AliceHincu)

set(CMAKE_CXX_STANDARD 14)

add_executable(a45_913AliceHincu main.cpp Console.cpp Console.h DynamicArray.h Dog.cpp Dog.h Tests.cpp Tests.h service/ServiceAdmin.cpp service/ServiceAdmin.h repository/RepositoryShelterDogs.cpp repository/RepositoryShelterDogs.h Exceptions.cpp Exceptions.h service/ServiceUser.cpp service/ServiceUser.h repository/RepositoryAdoptedDogs.cpp repository/RepositoryAdoptedDogs.h)