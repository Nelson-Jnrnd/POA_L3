#ifndef POA_L3_ADULT_HPP
#define POA_L3_ADULT_HPP

#include "Person.hpp"
#include "Child.hpp"

/**
 * Represent a Adult
 * @date 11-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Adult : public Person {
public:

   /**
    * Constructor
    * @param name
    */
   Adult(const std::string &name);

   /**
    * Method to know if an Adult can drive
    * @return true if possible
    */
   bool canDrive() const override;

   /**
    * Method to know if a person can be with specific people
    * @param people
    * @return a boolean and a message if an error
    */
   Response canBeWith(const std::list<const Person *> &people) const override;
};

#endif //POA_L3_ADULT_HPP
