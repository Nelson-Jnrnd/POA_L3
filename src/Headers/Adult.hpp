//
// Created by NelsonWork on 02.05.2022.
//

#ifndef POA_L3_ADULT_HPP
#define POA_L3_ADULT_HPP


#include "Person.hpp"

class Adult : public Person {
public:
    Adult(const std::string& name);
    bool canDrive() const override;
    bool hasFamily() const override;
};


#endif //POA_L3_ADULT_HPP
