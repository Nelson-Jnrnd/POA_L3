#ifndef POA_L3_POLICEMAN_HPP
#define POA_L3_POLICEMAN_HPP

#include "Adult.hpp"

/**
 * Represent a Policeman
 * @version 1.0
 * @date 11.05.2022
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Policeman : public Adult {
public:
    /**
     * Constructor
     * @param name
     */
    Policeman(const std::string name);
};

#endif //POA_L3_POLICEMAN_HPP
