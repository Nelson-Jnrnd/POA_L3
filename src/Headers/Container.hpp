#ifndef POA_L3_CONTAINER_HPP
#define POA_L3_CONTAINER_HPP

#include <string>
#include <list>
#include "Person.hpp"
#include "Constraint.hpp"

class Container {

public:
    bool canLeave(const Person &person) const;
    bool canArrive(const Person &person) const;

    void arrive(const Person &person);
    void leave(const Person &person);

    void arrive(const std::list<const Person*> &people);

    bool isHere(const Person &person) const;
protected:
    Container(const std::string& name, const std::list<const Constraint*>& constraints);
    Container(const std::string& name, const std::list<const Constraint*>& constraints, const std::list<const Person*>& people);

private:
    const std::string NAME;
    const std::list<const Constraint*> CONSTRAINTS;
    std::list<const Person*> peopleInContainer;
};

#endif //POA_L3_CONTAINER_HPP
