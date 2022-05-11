#ifndef POA_L3_PERSON_HPP
#define POA_L3_PERSON_HPP

#include <string>
#include <list>
#include "Response.hpp"

/**
 * Represent a person
 * @date 11-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Person {
public:
    /**
     * Method to know if a person can drive the boat
     * @return bool
     */
    virtual bool canDrive() const = 0;

    /**
     * Method to get the name
     * @return
     */
    std::string getName() const;

    /**
     * Method to know if a person can be with others
     * @param people
     * @return Response composed of a bool and string
     */
    virtual Response canBeWith(const std::list<const Person *> &people) const = 0;

    /**
    * Destructor
    */
    virtual ~Person() = default;

protected:
   /**
    * Constructor
    * @param name
    */
    Person(const std::string &name);
    
private:
    std::string name;
};

#endif //POA_L3_PERSON_HPP
