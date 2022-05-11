//
// Created by NelsonWork on 04.05.2022.
//

#include "Headers/Child.hpp"
#include <algorithm>

Child::Child(const std::string& name, const Adult &responsibleParent, const Adult &otherParent) : Person(name), responsibleParent(responsibleParent), otherParent(otherParent) {}

bool Child::canDrive() const {
    return false;
}

bool Child::canBeWith(const std::list<const Person *> &people) const {
    // Find the parents in the list
    auto otherParentIt = std::find(people.begin(), people.end(), &otherParent);
    auto responsibleParentIt = std::find(people.begin(), people.end(), &responsibleParent);
    // If the responsible parent is not in the list and the other parent is return false
    return !(responsibleParentIt == people.end() && otherParentIt != people.end());
}
