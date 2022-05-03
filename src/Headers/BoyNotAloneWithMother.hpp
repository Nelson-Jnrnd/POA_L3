//
// Created by NelsonWork on 03.05.2022.
//

#ifndef POA_L3_BOYNOTALONEWITHMOTHER_HPP
#define POA_L3_BOYNOTALONEWITHMOTHER_HPP


#include "Constraint.hpp"

/**
 * Represent a BoyNotAloneWithMother
 * @version 1.0
 * @date 03.05.2022
 * @author Nelson Jeanrenaud
 * @author 
 */
class BoyNotAloneWithMother : public Constraint{
public:
    bool isRespected(const std::list<const Person *> &people) const override;
private:
    BoyNotAloneWithMother() = default;
};


#endif //POA_L3_BOYNOTALONEWITHMOTHER_HPP
