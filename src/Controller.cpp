#include "Headers/Controller.hpp"
#include "Headers/Adult.hpp"
#include "Headers/Policeman.hpp"
#include "Headers/Thief.hpp"

#include <iostream>
#include <algorithm>

using std::cout;
using std::find;

Controller::Controller() {
    turnCount = 1;
    Adult* mother = new Adult("mother");
    Adult* father = new Adult("father");
    Policeman* policeman = new Policeman("policeman");
    peopleInGame.push_back(mother);
    peopleInGame.push_back(father);
    peopleInGame.push_back(new Child("julie", *mother, *father));
    peopleInGame.push_back(new Child("jeanne", *mother, *father));
    peopleInGame.push_back(new Child("pierre", *father, *mother));
    peopleInGame.push_back(new Child("paul", *father, *mother));
    peopleInGame.push_back(policeman);
    peopleInGame.push_back(new Thief("thief", policeman));

    leftBank = new Bank("leftBank", peopleInGame);
    rightBank = new Bank("rightBank");
    boat = new Boat("boat", *leftBank);
}

void Controller::embark(const std::string &name) {
   Controller::movePerson(name, embark);
}

void Controller::disembark(const std::string &name) {
   Controller::movePerson(name, disembark);
}

void Controller::moveBoat() {
    boat->move(std::addressof(boat->getPosition()) == leftBank ? *rightBank : *leftBank);
    turnCount++;
}

Bank *Controller::getBank(const Person &person) const{
    if (leftBank->isHere(person)) {
        return leftBank;
    } else if (rightBank->isHere(person)) {
        return rightBank;
    } else {
        return nullptr;
    }
}

void Controller::embark(const Person &person) {
    Bank *bank = getBank(person);
    if (bank != nullptr) {
        if (&boat->getPosition() == bank) {
            Response boatResponse = boat->canArrive(person);
            if (!boatResponse.isAllowed()) {
                throw std::invalid_argument(boatResponse.getReason());
            }
            Response bankResponse = bank->canLeave(person);
            if (!bankResponse.isAllowed()) {
                throw std::invalid_argument(bankResponse.getReason());
            }
            boat->arrive(person);
            bank->leave(person);
        } else {
            throw std::invalid_argument("Boat is not here to pickup " + person.getName());
        }
    } else {
        throw std::invalid_argument(person.getName() + " is already on boat");
    }
}

void Controller::disembark(const Person &person) {
    if (boat->isHere(person)) {
        Bank &location = boat->getPosition();
        Response boatResponse = boat->canLeave(person);
        if (!boatResponse.isAllowed()) {
            throw std::invalid_argument(boatResponse.getReason());
        }
        Response bankResponse = location.canArrive(person);
        if (!bankResponse.isAllowed()) {
            throw std::invalid_argument(bankResponse.getReason());
        }
        boat->leave(person);
        location.arrive(person);
    } else {
        throw std::invalid_argument(person.getName() + " is not on boat");
    }
}

const Person *Controller::findPerson(const std::string &name) const{
    for (auto it: peopleInGame) {
        if (it->getName() == name) {
            return it;
        }
    }
    return nullptr;
}


const Boat &Controller::getBoat() const {
    return *boat;
}

const Bank &Controller::getLeftBank() const {
    return *leftBank;
}

const Bank &Controller::getRightBank() const {
    return *rightBank;
}

Controller::~Controller() {
    delete leftBank;
    delete rightBank;
    delete boat;

    for (auto it: peopleInGame) {
        delete it;
    }
}

unsigned int Controller::getTurnCount() const {
    return turnCount;
}

void movePerson(const std::string &name, void (*function)(const Person&)){
   const Person *personToMove = findPerson(name);

   if (personToMove == nullptr) {
      throw std::invalid_argument("Person not found");
   } else {
      function(*personToMove);
      turnCount++;
   }
}


