#ifndef POA_L3_CONTROLLER_HPP
#define POA_L3_CONTROLLER_HPP


#include "Person.hpp"
#include "Boat.hpp"
#include "Bank.hpp"

class Controller {
public:
    Controller();

    void start();

private:
    static const std::list<const Person*> peopleInGame;
    Boat boat;
    Bank leftBank;
    Bank rightBank;
};


#endif //POA_L3_CONTROLLER_HPP
