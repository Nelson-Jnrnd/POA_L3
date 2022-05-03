#ifndef POA_L3_PERSON_HPP
#define POA_L3_PERSON_HPP


#include <string>

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

    /**
     * @brief returns if the person is part of a family.
     */
    virtual bool hasFamily() const = 0;

protected:
    Person(const std::string &name);
private:
    std::string name;
};


#endif //POA_L3_PERSON_HPP