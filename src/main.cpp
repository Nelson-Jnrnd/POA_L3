#include <iostream>
#include "Headers/Adult.hpp"
#include "Headers/Ruleset.hpp"
#include "Headers/Bank.hpp"

using std::endl;
using std::cout;

int main() {
    cout << "Create Rive gauche with people" << endl;

    Bank bank("Rive gauche", Ruleset::getPersons());

    cout << "Create Rive droite empty" << endl;

    Bank bank2("Rive droite");

    cout << "Create bateau" << endl;

    Adult natalie("Natalie");
    Adult john("John");

    Child julie = Adult::makeChild(natalie, john, "Julie");

    return EXIT_SUCCESS; // TODO pas oublier de mettre ça dans la dernière version
}
