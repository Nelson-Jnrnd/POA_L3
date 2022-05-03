//
// Created by NelsonWork on 03.05.2022.
//

#include "Headers/Ruleset.hpp"

#include <utility>
#include "Headers/Ruleset.hpp"
#include "Headers/Adult.hpp"

std::list<const Constraint *> Ruleset::getConstraints() {
    static std::list<const Constraint *> constraints = {};
    return {};
}

std::list<const Person *> Ruleset::getPersons() {
    static std::list<const Person *> persons = {new Adult("Tom"), new Adult("David")};
    return persons;
}