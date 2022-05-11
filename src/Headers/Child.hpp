#ifndef POA_L3_CHILD_HPP
#define POA_L3_CHILD_HPP

#include "Person.hpp"
#include "Adult.hpp"
class Adult;

/**
 * Represent a Child
 * @date 04-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Child : public Person {
public:

   /**
    * Constructor
    * @param name
    * @param responsibleParent parent of the same sex
    * @param otherParent
    */
   Child(const std::string& name, const Adult &responsibleParent, const Adult &otherParent);

   /**
    * Method to know if a child can drive boat
    * @return False
    */
   bool canDrive() const override;

   /**
    * Method to know if a child can be with specific people
    * @param people
    * @return bool and message if an error
    */
   Response canBeWith(const std::list<const Person *> &people) const override;

private:
   const Adult& responsibleParent;
   const Adult& otherParent;
};

#endif //POA_L3_CHILD_HPP
