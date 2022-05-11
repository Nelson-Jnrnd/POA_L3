#include "Headers/Adult.hpp"
#include "Headers/Child.hpp"

Adult::Adult(const std::string &name) : Person(name) {}

bool Adult::canDrive() const {
    return true;
}

Response Adult::canBeWith(const std::list<const Person *> &people) const {
    return Response(true);
}
