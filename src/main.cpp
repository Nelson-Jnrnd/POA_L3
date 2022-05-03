#include <iostream>
#include "Headers/Adult.hpp"
#include "Headers/Ruleset.hpp"
#include "Headers/Bank.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Bank bank("Rive gauche", Ruleset::getPersons());


    return 0;
}
