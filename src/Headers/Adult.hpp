#ifndef POA_L3_ADULT_HPP
#define POA_L3_ADULT_HPP

#include "Person.hpp"
#include "Child.hpp"

class Child;

/**
 * Represent a bank on the side of the river. It can contain people under certain conditions.
 * @date 11-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
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
