#ifndef POA_L3_THIEF_HPP
#define POA_L3_THIEF_HPP

#include "Adult.hpp"
#include "Policeman.hpp"

/**
 * Represent a Thief
 * @version 1.0
 * @date 11.05.2022
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Thief : public Adult {
public:

   /**
    * Constructor
    * @param name
    * @param policemanWatching Policeman watching over the thief
    */
   Thief(const std::string &name, const Policeman *policemanWatching);

   /**
    * Method to know if the thief can drive
    * @return False
    */
   bool canDrive() const override;

   /**
    * Method to know if the thief can be with other people
    * @param people
    * @return Bool
    */
   bool canBeWith(const std::list<const Person *> &people) const override;
private:
    const Policeman *policemanWatching;
};


#endif //POA_L3_THIEF_HPP
