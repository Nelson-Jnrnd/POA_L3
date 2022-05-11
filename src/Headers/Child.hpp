//
// Created by NelsonWork on 04.05.2022.
//

#ifndef POA_L3_CHILD_HPP
#define POA_L3_CHILD_HPP


#include "Person.hpp"
#include "Adult.hpp"
class Adult;

/**
 * Represent a Child
 * @version 1.0
 * @date 04.05.2022
 * @author Nelson Jeanrenaud
 * @author 
 */
class Child : public Person {
public:
    Child(const std::string& name, const Adult &responsibleParent, const Adult &otherParent);
    bool canDrive() const override;
    bool canBeWith(const std::list<const Person *> &people) const override;
private:
    const Adult& responsibleParent;
    const Adult& otherParent;
};

#endif //POA_L3_CHILD_HPP
