//
// Created by NelsonWork on 02.05.2022.
//

#ifndef POA_L3_ADULT_HPP
#define POA_L3_ADULT_HPP


#include "Person.hpp"
#include "Child.hpp"

class Child;

class Adult : public Person {
public:
    Adult(const std::string &name);

    static Child makeChild(Adult &parent1, Adult &parent2, const std::string &childName);

    bool canDrive() const override;

    bool canBeWith(const std::list<const Person *> &people) const override;
private:
    std::list<const Child *> children;

    void addChild(const Child &child);
};


#endif //POA_L3_ADULT_HPP
