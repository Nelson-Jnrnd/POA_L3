#ifndef POA_L3_BOAT_HPP
#define POA_L3_BOAT_HPP


#include "Container.hpp"

class Boat : public Container {
public:
    Boat(const std::string &name);
private:
    const static unsigned MAX_PASSENGERS = 2;
};


#endif //POA_L3_BOAT_HPP
