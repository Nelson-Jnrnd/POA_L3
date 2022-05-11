#include <stdexcept>
#include "Headers/Boat.hpp"

Boat::Boat(const std::string &name, Bank &boatPosition) :
    Container(name),
    position(&boatPosition){}

void Boat::move(Bank& newPosition) {
    // Can move only if atleast one of person on the boat can drive
    for (const Person* p : this->getPeople()) {
        if (p->canDrive()) {
            this->position = &newPosition;
            return;
        }
    }
    throw std::invalid_argument("No person on the boat can drive");
}

Bank &Boat::getPosition() const {
    return *position;
}

Response Boat::canArrive(const Person &personArriving) const {
    if(this->getPeople().size() >= MAX_PASSENGERS) {
        return Response(false, "Boat is full");
    }
    return Container::canArrive(personArriving);
}

