#include <iostream>
#include "Headers/Adult.hpp"
#include "Headers/Ruleset.hpp"
#include "Headers/Bank.hpp"
#include "Headers/Boat.hpp"
#include "Headers/Controller.hpp"

using std::endl;
using std::cout;

int main() {
    cout << "Create Rive gauche with people" << endl;

    Bank bank("Rive gauche", Ruleset::getPersons());

    cout << "Create Rive droite empty" << endl;

    Bank bank2("Rive droite");

    cout << "Create boat" << endl;

    Boat boat("Bateau");

    cout << "Create family" << endl;

    Adult natalie("Natalie");
    Adult john("John");

    Child julie = Adult::makeChild(natalie, john, "Julie");

    cout << "Add people to bank" << endl;

    bank.arrive(natalie);
    bank.arrive(john);
    bank.arrive(julie);

    cout << "moving people to boat" << endl;

    bank.leave(natalie);
    boat.arrive(natalie);

    Controller controller;

    controller.start();


    return EXIT_SUCCESS; // TODO pas oublier de mettre ça dans la dernière version
}
