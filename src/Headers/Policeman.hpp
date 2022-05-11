#ifndef POA_L3_POLICEMAN_HPP
#define POA_L3_POLICEMAN_HPP

#include "Adult.hpp"

/**
 * Represent a Policeman
 * @date 11-05-2022
 * @version 1.0
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
