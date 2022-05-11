#ifndef POA_L3_BANK_HPP
#define POA_L3_BANK_HPP

#include "Container.hpp"
#include "Person.hpp"
#include <string>

/**
 * Represent a bank on the side of the river. It can contain people under certain conditions.
 * @date 11-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Bank : public Container {
public:
   /**
    * Constructor
    * @param name the side of the river
    */
    Bank(const std::string &name);

    /**
     * Constructor
     * @param name the side of the river
     * @param people present on the bank
     */
    Bank(const std::string &name, const std::list<const Person*>& people);
};


#endif //POA_L3_BANK_HPP
