#ifndef POA_L3_BANK_HPP
#define POA_L3_BANK_HPP

#include "Container.hpp"
#include "Person.hpp"
#include <string>

/**
 * Represent a bank on the side of the river. It can contain people under certain conditions.
 * @date 2022-03-05
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class Bank : public Container {
public:
    Bank(const std::string &name, const std::list<const Person*> people);
};


#endif //POA_L3_BANK_HPP
