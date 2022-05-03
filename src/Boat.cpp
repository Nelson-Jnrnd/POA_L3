#include "Headers/Boat.hpp"
#include "Headers/Ruleset.hpp"

Boat::Boat(const std::string &name) : Container(name, Ruleset::getConstraints()){};