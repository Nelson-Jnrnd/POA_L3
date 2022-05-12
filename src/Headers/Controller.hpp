#ifndef POA_L3_CONTROLLER_HPP
#define POA_L3_CONTROLLER_HPP

#include "Person.hpp"
#include "Boat.hpp"
#include "Bank.hpp"

/**
* Represent the Controller of the game
* @date 11-05-2022
* @version 1.0
* @author Nelson Jeanrenaud
* @author André Marques Nora
*/
class Controller {
public:
   /**
    * Constructor
    */
    Controller();

    /**
     * Destructor
     */
    ~Controller();

    /**
     * Method to embark a person given the name
     * @param name of the person
     * @throw Error if doesn't respect rules
     */
    void embark(const std::string& name);

    /**
     * Method to disembark a person given the name
     * @param name of the person
     * @throw Error if doesn't respect rules
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

    /**
     * Method to get the number of turns played so far
     * @return unsigned int
     */
    unsigned int getTurnCount() const;
private:
    unsigned int turnCount;

    std::list<const Person*> peopleInGame;
    Boat* boat;
    Bank* leftBank;
    Bank* rightBank;


    /**
     * Method to find a person given the name
     * @param name of the person
     * @return Pointer to Person
     */
    const Person* findPerson(const std::string& name) const;

    /**
     * Method to get on which bank is a person
     * @param person
     * @return Bank
     */
    Bank* getBank(const Person& person) const;

    /**
     * Second Method to embark giving the Person directly
     * @param person
     * @throw Error if doesn't respect rules
     */
    void embark(const Person& person);

   /**
    * Second Method to disembark giving the Person directly
    * @param person
    * @throw Error if doesn't respect rules
    */
    void disembark(const Person& person);

    /**
     * Function to move a person
     * @param name
     * @param function to embark or disembark
     * @throw Error if person doesn't exist
     */
    void movePerson(const std::string &name, void (*function)(const Person&));
};

#endif //POA_L3_CONTROLLER_HPP
