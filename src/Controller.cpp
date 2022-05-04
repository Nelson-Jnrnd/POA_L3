#include "Headers/Controller.hpp"
#include "Headers/Adult.hpp"

#include <iostream>
using std::cout;

// TODO à modifier, grégoire va pleurer s'il voit ça
const std::list<const Person*> Controller::peopleInGame = [] {

    static Adult alicia("alicia");
    static Adult mike("mike");
    static Child isaac = Adult::makeChild(alicia, mike, "isaac");
    static Child nina = Adult::makeChild(alicia, mike, "nina");
    static Child arthur = Adult::makeChild(alicia, mike, "arthur");

    std::list<const Person*> people;
    people.push_back(&alicia);
    people.push_back(&mike);
    people.push_back(&isaac);
    people.push_back(&nina);
    people.push_back(&arthur);
    return people;
}();

Controller::Controller() :
        leftBank("leftBank", peopleInGame),
        rightBank("rightBank"),
        boat("boat") {}

void Controller::start() {
    while (true) {
        std::cout << "Welcome to the game.\n";
        break;
    }
}
