#include "Headers/Bank.hpp"

Bank::Bank(const std::string &name, const std::list<const Person *> people) : Container(name, people) {}

Bank::Bank(const std::string &name) : Container(name) {}
