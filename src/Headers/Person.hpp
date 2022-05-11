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
     * @brief returns if the person is allowed to drive the boat.
    */
    virtual bool canDrive() const = 0;
    std::string getName() const;
    virtual bool canBeWith(const std::list<const Person *> &people) const = 0;
protected:
    Person(const std::string &name);
private:
    std::string name;
};


#endif //POA_L3_PERSON_HPP
