//
// Created by NelsonWork on 02.05.2022.
//

#ifndef POA_L3_CONSTRAINT_HPP
#define POA_L3_CONSTRAINT_HPP

#include <list>
#include <Headers/Person.hpp>

class Constraint {
public:
    virtual bool isRespected(const std::list<const Person *> &people) const = 0;

    bool isRespected(const std::list<const Person *> &people, const Person &person) const;

protected:
    Constraint() = default;
};


#endif //POA_L3_CONSTRAINT_HPP
