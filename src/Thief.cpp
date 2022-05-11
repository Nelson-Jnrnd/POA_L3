//
// Created by NelsonWork on 11.05.2022.
//

#include "Headers/Thief.hpp"
#include <algorithm>

bool Thief::canDrive() const {
    return false;
}

Response Thief::canBeWith(const std::list<const Person *> &people) const {
    Response personResponse = Adult::canBeWith(people);
    if(!personResponse.isAllowed()) {
        return personResponse;
    }
    // cast policeman into person
    const auto policeman = dynamic_cast<const Person*>(policemanWatching);
    auto policemanFound = std::find(people.begin(), people.end(), &*policeman);
    if(policemanFound == people.end() && people.size() > 1) {
        return Response(false, getName() + " can't be with other people without " + policeman->getName() + " watching him");
    }
    return Response(true);
}


Thief::Thief(const std::string &name, const Policeman *policemanWatching) : Adult(name),
                                                                      policemanWatching(policemanWatching) {}
