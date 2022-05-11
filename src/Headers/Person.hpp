#ifndef POA_L3_PERSON_HPP
#define POA_L3_PERSON_HPP

#include <string>
#include <list>

/**
 * @brief Represents a person to be transported over the river.
 * @author Nelson Jeanrenaud
 * @version 1.0
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
     * @return bool
     */
    virtual bool canBeWith(const std::list<const Person *> &people) const = 0;
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
