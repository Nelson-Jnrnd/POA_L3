#include "Headers/Boat.hpp"
#include "Headers/Ruleset.hpp"

Boat::Boat(const std::string &name, Bank &boatPosition) :
    Container(name, Ruleset::getConstraints()),
    position(&boatPosition){}

void Boat::move(Bank& newPosition) {
    position = &newPosition;
}

Bank &Boat::getPosition() const {
    return *position;
}

