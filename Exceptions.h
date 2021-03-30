//
// Created by Sakura on 3/30/2021.
//

#ifndef A45_913ALICEHINCU_EXCEPTIONS_H
#define A45_913ALICEHINCU_EXCEPTIONS_H


#include <exception>
#include <string>

class Exceptions : public std::exception {
private:
    std::string _msg;
public:
    Exceptions(std::string  msg);
    const std::string& get_msg() const;
};


#endif //A45_913ALICEHINCU_EXCEPTIONS_H
