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
        src/Headers/Ruleset.hpp
        src/Child.cpp
        src/Headers/Child.hpp src/Headers/ConsoleInterface.cpp src/Headers/ConsoleInterface.hpp src/Headers/Thief.cpp src/Headers/Thief.hpp src/Headers/Policeman.cpp src/Headers/Policeman.hpp)

