#include "Headers/Child.hpp"
#include <algorithm>

Child::Child(const std::string& name, const Adult &responsibleParent, const Adult &otherParent) : Person(name), responsibleParent(responsibleParent), otherParent(otherParent) {}

bool Child::canDrive() const {
    return false;
}

Response Child::canBeWith(const std::list<const Person *> &people) const {
    // Find the parents in the list
    auto otherParentIt = std::find(people.begin(), people.end(), &otherParent);
    auto responsibleParentIt = std::find(people.begin(), people.end(), &responsibleParent);
    // If the responsible parent is not in the list and the other parent is return false
    if(!(responsibleParentIt == people.end() && otherParentIt != people.end())){
        return Response(true);
    }
    return Response(false, getName() + " cannot be with " + otherParent.getName() + " if " + responsibleParent.getName() + " is not here");
}
