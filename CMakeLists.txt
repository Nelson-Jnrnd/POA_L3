cmake_minimum_required(VERSION 3.17)
project(POA_L3)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(POA_L3
        src/main.cpp
        src/Bank.cpp
        src/Headers/Bank.hpp
        src/Boat.cpp
        src/Headers/Boat.hpp
        src/Container.cpp
        src/Headers/Container.hpp
        src/Controller.cpp
        src/Headers/Controller.hpp
        src/Person.cpp
        src/Headers/Person.hpp
        src/Adult.cpp
        src/Headers/Adult.hpp
        src/Ruleset.cpp
        src/Headers/Ruleset.hpp src/Headers/BoyNotAloneWithMother.cpp src/Headers/BoyNotAloneWithMother.hpp)

