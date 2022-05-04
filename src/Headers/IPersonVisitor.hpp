//
// Created by NelsonWork on 04.05.2022.
//

#ifndef POA_L3_IPERSONVISITOR_HPP
#define POA_L3_IPERSONVISITOR_HPP


#include "Adult.hpp"

/**
 * Represent a IPersonVisitor
 * @version 1.0
 * @date 04.05.2022
 * @author Nelson Jeanrenaud
 * @author 
 */
class IPersonVisitor {
    public:
    virtual ~IPersonVisitor() = default;
    virtual void visit(const Adult &adult) = 0;
    virtual void visit(const Child &child) = 0;
};


#endif //POA_L3_IPERSONVISITOR_HPP
