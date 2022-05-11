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
    static Child isaac = Adult::makeChild(alicia, mike, "isaac");
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
    const Person* personToMove = findPerson(name);

    if(personToMove == nullptr) {
        throw std::invalid_argument("Person not found");
    } else {
        embark(*personToMove);
    }
}

void Controller::disembark(const std::string &name) {
    const Person* personToMove = findPerson(name);

    if(personToMove == nullptr) {
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
    if(bank != nullptr) {
        if (&boat.getPosition() == bank) {
            if (boat.canArrive(person) && bank->canLeave(person)) {
                boat.arrive(person);
                bank->leave(person); // TODO y a un double check qu'il faudrait remove
            } else {
                throw std::invalid_argument("Person cannot embark");
            }
        } else {
            throw std::invalid_argument("Boat is not here to pickup the person");
        }    } else {
        throw std::invalid_argument("Person cannot embark");
    }
}

void Controller::disembark(const Person &person) {
    if (boat.isHere(person)) {
        Bank &location = boat.getPosition();
        if (location.canArrive(person) && boat.canLeave(person)) {
            location.arrive(person);
            boat.leave(person);
        } else {
            throw std::invalid_argument("Person cannot disembark");
        }
    } else {
        throw std::invalid_argument("Person is not on boat");
    }
}

const Person *Controller::findPerson(const std::string &name) const {
    for (auto it : peopleInGame) {
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


