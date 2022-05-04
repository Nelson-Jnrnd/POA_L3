//
// Created by NelsonWork on 04.05.2022.
//

#include "Headers/Child.hpp"

Child::Child(const std::string& name, const Adult &parent1, const Adult &parent2) : Person(name), PARENT1(parent1), PARENT2(parent2) {}