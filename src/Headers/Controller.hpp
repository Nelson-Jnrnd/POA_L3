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

    // Remove copy constructor and assignment operator
    Controller(const Controller&) = delete;
    Controller& operator=(const Controller&) = delete;

    /**
     * Method to embarkPerson a person given the name
     * @param name of the person
     * @throw Error if doesn't respect rules
     */
    void embark(const std::string& name);

    /**
     * Method to disembarkPerson a person given the name
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
    /**
     * Type of way we can move a person
     */
    enum class MoveType {EMBARK, DISEMBARK};

    unsigned int turnCount;

    std::list<const Person*> peopleInGame;
    Boat* boat;
    Bank* leftBank;
    Bank* rightBank;

    /**
     * Move a person depending on the moveType
     * @param moveType way we move a person
     * @param name person to move
     */
    void doMove(MoveType moveType, const std::string& name);

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
     * Second Method to embarkPerson giving the Person directly
     * @param person
     * @throw Error if doesn't respect rules
     */
    void embarkPerson(const Person& person);

   /**
    * Second Method to disembarkPerson giving the Person directly
    * @param person
    * @throw Error if doesn't respect rules
    */
    void disembarkPerson(const Person& person);

};

#endif //POA_L3_CONTROLLER_HPP
