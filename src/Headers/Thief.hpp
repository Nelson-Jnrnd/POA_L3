//
// Created by NelsonWork on 11.05.2022.
//

#ifndef POA_L3_THIEF_HPP
#define POA_L3_THIEF_HPP


#include "Adult.hpp"
#include "Policeman.hpp"

/**
 * Represent a Thief
 * @version 1.0
 * @date 11.05.2022
 * @author Nelson Jeanrenaud
 * @author 
 */
class Thief : public Adult {
public:
    Thief(const std::string &name, const Policeman *policemanWatching);

    bool canDrive() const override;
    bool canBeWith(const std::list<const Person *> &people) const override;
private:
    const Policeman *policemanWatching;
};


#endif //POA_L3_THIEF_HPP
