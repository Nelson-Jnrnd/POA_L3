#include <iostream>
#include "Headers/Adult.hpp"
#include "Headers/Ruleset.hpp"
#include "Headers/Bank.hpp"
#include "Headers/Boat.hpp"
#include "Headers/Controller.hpp"

using std::endl;
using std::cout;

int main() {


    Controller controller;

    controller.start();


    return EXIT_SUCCESS; // TODO pas oublier de mettre ça dans la dernière version
}
