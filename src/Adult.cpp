//
// Created by NelsonWork on 02.05.2022.
//

#include "Headers/Adult.hpp"

Adult::Adult(const std::string &name) : Person(name) {}

bool Adult::hasFamily() const {
    return false;
}

bool Adult::canDrive() const {
    return true;
}
