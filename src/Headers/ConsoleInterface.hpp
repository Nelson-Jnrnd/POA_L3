//
// Created by NelsonWork on 04.05.2022.
//

#ifndef POA_L3_CONSOLEINTERFACE_HPP
#define POA_L3_CONSOLEINTERFACE_HPP


#include <ostream>
#include "Controller.hpp"

/**
 * Represent a ConsoleInterface
 * @version 1.0
 * @date 04.05.2022
 * @author Nelson Jeanrenaud
 * @author 
 */
class ConsoleInterface {
public:
    ConsoleInterface() = delete;
    ConsoleInterface(const ConsoleInterface&) = delete;
    ConsoleInterface& operator=(const ConsoleInterface&) = delete;

    static void playGame(std::istream &input, std::ostream &output);
private:
    static const char DISPLAY_CHAR;
    static const char EMBARK_CHAR;
    static const char DISEMBARK_CHAR;
    static const char MOVE_BOAT_CHAR;
    static const char RESET_CHAR;
    static const char QUIT_CHAR;
    static const char MENU_CHAR;
    static const unsigned CHARS_PER_LINE;
    static const char LINE_CHAR;
    static const char RIVER_CHAR;

    static void printHelp(std::ostream &output) ;
    static void printContainer(std::ostream &output, const Container& container);
    static void printLine(std::ostream &output);
    static void printRiver(std::ostream &output);
};


#endif //POA_L3_CONSOLEINTERFACE_HPP
