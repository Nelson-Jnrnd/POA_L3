#ifndef POA_L3_CONTAINER_HPP
#define POA_L3_CONTAINER_HPP

#include <string>
#include <list>
#include "Person.hpp"

/**
 * Represent all containable object in project
 * @date 11-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Container {
public:
   /**
    * Method to check if a person can leave a container
    * @param personLeaving
    * @return true if can leave or false if not
    */
    Response canLeave(const Person &personLeaving) const;
    virtual Response canArrive(const Person &personArriving) const;

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
