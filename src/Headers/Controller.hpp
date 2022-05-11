#ifndef POA_L3_CONTROLLER_HPP
#define POA_L3_CONTROLLER_HPP


#include "Person.hpp"
#include "Boat.hpp"
#include "Bank.hpp"

class Controller {
public:
    Controller();

    void embark(const std::string& name);
    void disembark(const std::string& name);
    void moveBoat();

    const Boat &getBoat() const;

    const Bank &getLeftBank() const;

    const Bank &getRightBank() const;
private:
    static const std::list<const Person*> peopleInGame;
    Boat boat;
    Bank leftBank;
    Bank rightBank;

    const Person* findPerson(const std::string& name) const;
    Bank* getBank(const Person& person);
    void embark(const Person& person);
    void disembark(const Person& person);
};


#endif //POA_L3_CONTROLLER_HPP
