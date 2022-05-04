//
// Created by NelsonWork on 04.05.2022.
//

#ifndef POA_L3_PERSONCONSTRAINTS_HPP
#define POA_L3_PERSONCONSTRAINTS_HPP


#include "IPersonVisitor.hpp"
#include "Constraint.hpp"

/**
 * Represent a PersonConstraints
 * @version 1.0
 * @date 04.05.2022
 * @author Nelson Jeanrenaud
 * @author 
 */
class PersonConstraints : public IPersonVisitor{
public:
    void visit(const Adult &adult) override;
    void visit(const Child &child) override;
private:
    PersonConstraints() = default;

    class BoyNotWithMother : public Constraint {
    public:
        bool isRespected(const std::list<const Person *> &people) const;
    };
};


#endif //POA_L3_PERSONCONSTRAINTS_HPP
