#ifndef POA_L3_BOAT_HPP
#define POA_L3_BOAT_HPP

#include "Container.hpp"
#include "Bank.hpp"

/**
 * Represent a boat. It can contain people under certain conditions.
 * @date 11-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Boat : public Container {
public:
   /**
    * Constructor
    * @param name of the person that boards
    * @param boatPosition on which bank it's on
    */
    Boat(const std::string &name, Bank& boatPosition);

    /**
     * Method to switch bank
     * @param newPosition the bank to move to
     */
    void move(Bank& newPosition);

    /**
     * Method to return the bank the boat is on
     * @return on which bank the boat is
     */
    Bank& getPosition() const;

    bool canArrive(const Person &personArriving) const override;
private:
    const static unsigned MAX_PASSENGERS = 2;
    Bank* position;
};


#endif //POA_L3_BOAT_HPP
