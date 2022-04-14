cmake_minimum_required(VERSION 3.21)
project(POA_L3)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(POA_L3
        src/Bank.cpp
        src/Headers/Bank.h
        src/Boat.cpp
        src/Headers/Boat.h
        src/Container.cpp
        src/Headers/Container.h
        src/Controller.cpp
        src/Headers/Controller.h
        src/Person.cpp
        src/Headers/Person.h)
