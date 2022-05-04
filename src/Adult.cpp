//
// Created by NelsonWork on 02.05.2022.
//

#include "Headers/Adult.hpp"
#include "Headers/Child.hpp"

Adult::Adult(const std::string &name) : Person(name), children() {
}
/*
bool Adult::canDrive() const {
    return true;
}*/

Child Adult::makeChild(Adult& parent1, Adult& parent2, const std::string& childName) { // TODO y a un truc que je compreds pas pk je peux pas passer par référence
    Child output(childName, parent1, parent2);
    parent1.addChild(output);
    parent2.addChild(output);
    return output;
}

void Adult::addChild(const Child &child) {
    children.push_back(&child);
}
