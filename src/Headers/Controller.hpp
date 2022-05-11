#ifndef POA_L3_CONTROLLER_HPP
#define POA_L3_CONTROLLER_HPP

#include "Person.hpp"
#include "Boat.hpp"
#include "Bank.hpp"


class Controller {
public:
   /**
    * Constructor
    */
    Controller();

    /**
     * Method to embark a person given the name
     * @param name of the person
     */
    void embark(const std::string& name);

    /**
     * Method to disembark a person given the name
     * @param name of the person
     */
    void disembark(const std::string& name);

    /**
     * Method to move the boat to another bank
     */
    void moveBoat();

    /**
     * Method to get the boat
     * @return Boat
     */
    const Boat &getBoat() const;

    /**
     * Method to get the left bank of the river
     * @return Bank
     */
    const Bank &getLeftBank() const;

   /**
    * Method to get the right bank of the river
    * @return Bank
    */
    const Bank &getRightBank() const;

private:
    static const std::list<const Person*> peopleInGame;
    Boat boat;
    Bank leftBank;
    Bank rightBank;

    /**
     * Method to find a person given the name
     * @param name of the person
     * @return Pointer to Person
     */
    static const Person* findPerson(const std::string& name) const;

    /**
     * Method to get on which bank is a person
     * @param person
     * @return Bank
     */
    Bank* getBank(const Person& person);

    /**
     * Second Method to embark giving the Person directly
     * @param person
     */
    void embark(const Person& person);

   /**
    * Second Method to disembark giving the Person directly
    * @param person
    */
    void disembark(const Person& person);
};


#endif //POA_L3_CONTROLLER_HPP
