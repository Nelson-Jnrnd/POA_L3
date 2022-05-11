#ifndef POA_L3_CONSOLEINTERFACE_HPP
#define POA_L3_CONSOLEINTERFACE_HPP

#include <ostream>
#include "Controller.hpp"

/**
 * Represent a ConsoleInterface
 * @date 11-05-2022
 * @version 1.0
 * @author Nelson Jeanrenaud
 * @author André Marques Nora
 */
class ConsoleInterface {
public:

   /**
    * Constructor
    */
   ConsoleInterface() = delete;

   /**
    * Constructor of copy
    */
   ConsoleInterface(const ConsoleInterface&) = delete;

   /**
    * Operator of affectation
    * @return reference of a ConsoleInterface object
    */
   ConsoleInterface& operator=(const ConsoleInterface&) = delete;

   /**
    * Method to launch game and play
    * @param input of the user
    * @param output of the game
    */
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

   /**
    * Method to display on the terminal the help commande
    * @param output of the game
    */
   static void printHelp(std::ostream &output) ;

   /**
    * Method to display on the terminal a container
    * @param output of the game
    * @param container to display
    */
   static void printContainer(std::ostream &output, const Container& container);

   /**
    * Method to display boundary of river
    * @param output
    */
   static void printLine(std::ostream &output);

   /**
    * Method to display the river
    * @param output
    */
   static void printRiver(std::ostream &output);
};

#endif //POA_L3_CONSOLEINTERFACE_HPP
