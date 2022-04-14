#ifndef POA_L3_CONTAINER_H
#define POA_L3_CONTAINER_H

#include <string>
#include <list>
#include "Person.h"

class Container {
   std::string name;
   std::list<const Person*> person;

   
};

#endif //POA_L3_CONTAINER_H
