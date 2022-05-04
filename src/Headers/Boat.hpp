#ifndef POA_L3_BOAT_HPP
#define POA_L3_BOAT_HPP


#include "Container.hpp"
#include "Bank.hpp"

class Boat : public Container {
public:
    Boat(const std::string &name, Bank& boatPosition);
    void move(Bank& newPosition);
    Bank& getPosition() const;
private:
    const static unsigned MAX_PASSENGERS = 2;
    Bank* position;
};


#endif //POA_L3_BOAT_HPP
