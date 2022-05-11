#include "Headers/Container.hpp"
#include <stdexcept>
#include <algorithm>


Container::Container(const std::string& name)
    : NAME(name) {

}

Container::Container(const std::string& name, const std::list<const Person*>& people)
    : Container(name) {
        arrive(people);
}

void Container::arrive(const Person& personArriving){
    if (!canArrive(personArriving).isAllowed()) {
        throw std::invalid_argument("Combination of constraints and people is not possible");
    }
    this->peopleInContainer.push_back(&personArriving);
}

void Container::arrive(const std::list<const Person*>& peopleArriving){
    for (const Person* person : peopleArriving) {
        if (person == nullptr) {
            throw std::invalid_argument("Person cannot be nullptr");
        }
        arrive(*person);
    }
}

Response Container::canArrive(const Person& personArriving) const {
    // Creates a new list of people with the personArriving
    std::list<const Person*> people = getPeople();
    people.push_back(&personArriving);
    for (const Person* person : people) {
        Response resp = person->canBeWith(people);
        if(!resp.isAllowed()){
            return resp;
        }
    }
    return Response(true);
}

void Container::leave(const Person &personLeaving) {
    if (!canLeave(personLeaving).isAllowed()) {
        throw std::invalid_argument("Combination of constraints and people is not possible");
    }
    this->peopleInContainer.remove(&personLeaving);
}

Response Container::canLeave(const Person &personLeaving) const {
    // Creates a new list of people with the personArriving
    std::list<const Person*> people = getPeople();
    people.remove(&personLeaving);
    for (const Person* person : people) {
        Response resp = person->canBeWith(people);
        if(!resp.isAllowed()){
            return resp;
        }
    }
    return Response(true);
}

bool Container::isHere(const Person &person) const {
    return std::find(this->peopleInContainer.begin(), this->peopleInContainer.end(), &person) != this->peopleInContainer.end();
}

std::string Container::getName() const {
    return this->NAME;
}

std::list<const Person *> Container::getPeople() const {
    return this->peopleInContainer;
}
