//
// Created by NelsonWork on 04.05.2022.
//

#include "Headers/PersonConstraints.hpp"

void PersonConstraints::visit(const Adult &adult) {
}

bool PersonConstraints::BoyNotWithMother::isRespected(const std::list<const Person *> &people) const {
    return false;
}
