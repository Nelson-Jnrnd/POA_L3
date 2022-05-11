//
// Created by NelsonWork on 11.05.2022.
//

#include "Headers/Thief.hpp"
#include <algorithm>

bool Thief::canDrive() const {
    return false;
}

bool Thief::canBeWith(const std::list<const Person *> &people) const {
    if(!Adult::canBeWith(people)) {
        return false;
    }
    // cast policeman into person
    const auto policeman = dynamic_cast<const Person*>(policemanWatching);
    auto policemanFound = std::find(people.begin(), people.end(), &*policeman);
    if(policemanFound == people.end() && people.size() > 1) {
        return false;
    }
    return true;
}


Thief::Thief(const std::string &name, const Policeman *policemanWatching) : Adult(name),
                                                                      policemanWatching(policemanWatching) {}
