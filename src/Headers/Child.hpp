//
// Created by NelsonWork on 04.05.2022.
//

#ifndef POA_L3_CHILD_HPP
#define POA_L3_CHILD_HPP


#include "Person.hpp"
#include "Adult.hpp"
class Adult;

/**
 * Represent a Child
 * @version 1.0
 * @date 04.05.2022
 * @author Nelson Jeanrenaud
 * @author 
 */
class Child : public Person {
public:
    Child(const std::string& name, const Adult &parent1, const Adult &parent2);

private:
    const Adult& PARENT1;
    const Adult& PARENT2;
};

#endif //POA_L3_CHILD_HPP
