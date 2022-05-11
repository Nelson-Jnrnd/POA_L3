#include "Headers/Controller.hpp"
#include "Headers/Adult.hpp"
#include "Headers/Policeman.hpp"
#include "Headers/Thief.hpp"

#include <iostream>
#include <algorithm>

using std::cout;
using std::find;


// TODO à modifier, grégoire va pleurer s'il voit ça
const std::list<const Person *> Controller::peopleInGame = [] {

    static Adult alicia("alicia");
    static Adult mike("mike");
    static Child isaac = Adult::makeChild(mike, alicia, "isaac");
    static Child nina = Adult::makeChild(alicia, mike, "nina");
    static Child arthur = Adult::makeChild(alicia, mike, "arthur");

    static Policeman james("james");
    static Thief thomas("thomas", &james);

    std::list<const Person *> people;
    people.push_back(&alicia);
    people.push_back(&mike);
    people.push_back(&isaac);
    people.push_back(&nina);
    people.push_back(&arthur);
    people.push_back(&james);
    people.push_back(&thomas);
    return people;
}();

Controller::Controller() :
        leftBank("leftBank", peopleInGame),
        rightBank("rightBank"),
        boat("boat", leftBank) {}


void Controller::embark(const std::string &name) {
    const Person *personToMove = findPerson(name);

    if (personToMove == nullptr) {
        throw std::invalid_argument("Person not found");
    } else {
        embark(*personToMove);
    }
}

void Controller::disembark(const std::string &name) {
    const Person *personToMove = findPerson(name);

    if (personToMove == nullptr) {
        throw std::invalid_argument("Person not found");
    } else {
        disembark(*personToMove);
    }
}

Bank *Controller::getBank(const Person &person) {
    if (leftBank.isHere(person)) {
        return &leftBank;
    } else if (rightBank.isHere(person)) {
        return &rightBank;
    } else {
        return nullptr;
    }
}

void Controller::embark(const Person &person) {
    Bank *bank = getBank(person);
    if (bank != nullptr) {
        if (&boat.getPosition() == bank) {
            Response boatResponse = boat.canArrive(person);
            if (!boatResponse.isAllowed()) {
                throw std::invalid_argument(boatResponse.getReason());
            }
            Response bankResponse = bank->canLeave(person);
            if (!bankResponse.isAllowed()) {
                throw std::invalid_argument(bankResponse.getReason());
            }
            boat.arrive(person);
            bank->leave(person); // TODO y a un double check qu'il faudrait remove
        } else {
            throw std::invalid_argument("Boat is not here to pickup " + person.getName());
        }
    } else {
        throw std::invalid_argument(person.getName() + " is already on boat");
    }
}

void Controller::disembark(const Person &person) {
    if (boat.isHere(person)) {
        Bank &location = boat.getPosition();
        Response boatResponse = boat.canLeave(person);
        if (!boatResponse.isAllowed()) {
            throw std::invalid_argument(boatResponse.getReason());
        }
        Response bankResponse = location.canArrive(person);
        if (!bankResponse.isAllowed()) {
            throw std::invalid_argument(bankResponse.getReason());
        }
        boat.leave(person);
        location.arrive(person); // TODO y a un double check qu'il faudrait remove
    } else {
        throw std::invalid_argument(person.getName() + " is not on boat");
    }
}

const Person *Controller::findPerson(const std::string &name) {
    for (auto it: peopleInGame) {
        if (it->getName() == name) {
            return it;
        }
    }
    return nullptr;
}

void Controller::moveBoat() {
    boat.move(&boat.getPosition() == &leftBank ? rightBank : leftBank);
}

const Boat &Controller::getBoat() const {
    return boat;
}

const Bank &Controller::getLeftBank() const {
    return leftBank;
}

const Bank &Controller::getRightBank() const {
    return rightBank;
}


