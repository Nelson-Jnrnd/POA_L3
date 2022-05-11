#ifndef POA_L3_CONTAINER_HPP
#define POA_L3_CONTAINER_HPP

#include <string>
#include <list>
#include "Person.hpp"
#include "Constraint.hpp"

class Container {

public:
    bool canLeave(const Person &personLeaving) const;
    bool canArrive(const Person &personArriving) const;

    void arrive(const Person &personArriving);
    void leave(const Person &personLeaving);

    void arrive(const std::list<const Person*> &peopleArriving);

    bool isHere(const Person &person) const;

    std::string getName() const;

    std::list<const Person*> getPeople() const;
protected:
    Container(const std::string& name);
    Container(const std::string& name, const std::list<const Person*>& people);

private:
    const std::string NAME;
    std::list<const Person*> peopleInContainer;
};

#endif //POA_L3_CONTAINER_HPP
