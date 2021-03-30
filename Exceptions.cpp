//
// Created by Sakura on 3/30/2021.
//

#include "Exceptions.h"

#include <utility>

Exceptions::Exceptions(std::string msg): std::exception(), _msg{std::move(msg)} {}

const std::string &Exceptions::get_msg() const {
    return this->_msg;
}