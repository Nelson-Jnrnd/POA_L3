#include "Headers/Bank.hpp"
#include "Headers/Ruleset.hpp"

Bank::Bank(const std::string &name, const std::list<const Person *> people) : Container(name, Ruleset::getConstraints(), people) {}

Bank::Bank(const std::string &name) : Container(name, Ruleset::getConstraints()) {}

