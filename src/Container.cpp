//
// Created by André on 14.04.2022.
//

#include "Headers/Container.hpp"
#include <stdexcept>

Container::Container(const std::string& name, const std::list<const Constraint*>& constraints) 
    : NAME(name), CONSTRAINTS(constraints) {

}

Container::Container(const std::string& name, const std::list<const Constraint*>& constraints, const std::list<const Person*>& people) 
    : Container(name, constraints) {
        arrive(people);
}

void Container::arrive(const Person& person){
    if (!canArrive(person)) {
        throw std::invalid_argument("Combination of constraints and people is not possible");
    }
    this->peopleInContainer.push_back(&person);
}

void Container::arrive(const std::list<const Person*>& people){
    for (const Person* person : people) {
        if (person == nullptr) {
            throw std::invalid_argument("Person cannot be nullptr");
        }
        arrive(*person);
    }
}

bool Container::canArrive(const Person& person) const {
    for (const Constraint* constraint : CONSTRAINTS) {
       /* if (!constraint->isRespected(this->peopleInContainer, person)) {
            return false;
        }*/
    }
    return true;
}

void Container::leave(const Person &person) {
    if (!canLeave(person)) {
        throw std::invalid_argument("Combination of constraints and people is not possible");
    }
    this->peopleInContainer.remove(&person);
}

bool Container::canLeave(const Person &person) const {
    for (const Constraint* constraint : CONSTRAINTS) {
        /*if (!constraint->isRespected(this->peopleInContainer, person)) {
            return false;
        }*/
    }
    return true;
}