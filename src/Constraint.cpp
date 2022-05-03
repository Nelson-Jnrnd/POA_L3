#include "Headers/Constraint.hpp"

bool Constraint::isRespected(const std::list<const Person*> &people, const Person &person) const {
    std::list<const Person*> peopleCopy = people;
    peopleCopy.push_back(&person);
    return isRespected(peopleCopy);
}