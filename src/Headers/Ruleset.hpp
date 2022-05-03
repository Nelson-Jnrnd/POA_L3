//
// Created by NelsonWork on 03.05.2022.
//

#ifndef POA_L3_RULESET_HPP
#define POA_L3_RULESET_HPP


#include "Constraint.hpp"

/**
 * Represent a Ruleset
 * @version 1.0
 * @date 03.05.2022
 * @author Nelson Jeanrenaud
 * @author 
 */
class Ruleset {
public:
    static std::list<const Constraint*> getConstraints();
    static std::list<const Person*> getPersons();
    Ruleset(Ruleset const&) = delete;
    void operator=(Ruleset const&) = delete;
    Ruleset() = delete;
};


#endif //POA_L3_RULESET_HPP
