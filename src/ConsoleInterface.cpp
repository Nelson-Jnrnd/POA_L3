#include "Headers/ConsoleInterface.hpp"

#include <iostream>
#include <limits>

using std::cout;
using std::ostream;
using std::istream;
using std::endl;
using std::string;

const char ConsoleInterface::DISPLAY_CHAR = 'p';
const char ConsoleInterface::EMBARK_CHAR = 'e';
const char ConsoleInterface::DISEMBARK_CHAR = 'd';
const char ConsoleInterface::MOVE_BOAT_CHAR = 'm';
const char ConsoleInterface::RESET_CHAR = 'r';
const char ConsoleInterface::QUIT_CHAR = 'q';
const char ConsoleInterface::MENU_CHAR = 'h';
const unsigned ConsoleInterface::CHARS_PER_LINE = 80;
const char ConsoleInterface::LINE_CHAR = '-';
const char ConsoleInterface::RIVER_CHAR = '=';


void ConsoleInterface::playGame(istream &input, ostream &output) {
    Controller* controller = new Controller();

    output << "Welcome to the game!" << endl;
    printHelp(output);

    while (true) {
        output << endl;
        output << controller->getTurnCount() << "> Enter a command: ";

        string command;
        string name;
        input >> command;
        if(command.size() != 1) {
            output << "Unknown command" << endl;
        } else {
            output << endl;
            try {
                switch (command[0]) {
                    case DISPLAY_CHAR:
                        printLine(output);
                        printContainer(output, controller->getLeftBank());
                        printLine(output);
                        if (&controller->getBoat().getPosition() ==
                            &controller->getLeftBank()) {
                            printContainer(output, controller->getBoat());
                            printRiver(output);
                            output << endl;
                        } else {
                            output << endl;
                            printRiver(output);
                            printContainer(output, controller->getBoat());
                        }
                        printLine(output);
                        printContainer(output, controller->getRightBank());
                        printLine(output);
                        break;
                    case EMBARK_CHAR:
                    case DISEMBARK_CHAR:
                        input >> name;
                        if (command[0] == EMBARK_CHAR) {
                            output << "Embarking..." << endl;
                            controller->embark(name);
                        } else {
                            output << "Disembarking..." << endl;
                            controller->disembark(name);
                        }
                        break;
                    case MOVE_BOAT_CHAR:
                        output << "Moving boat..." << endl;
                        controller->moveBoat();
                        break;
                    case RESET_CHAR:
                        output << "Resetting..." << endl;
                        delete controller;
                        controller = new Controller();
                        break;
                    case QUIT_CHAR:
                        output << "Quitting..." << endl;
                        delete controller;
                        return;
                    case MENU_CHAR:
                        printHelp(output);
                        break;
                    default:
                        output << "Unknown command" << endl;
                        break;
                }
            }
            catch (const std::invalid_argument &e) {
                output << "Invalid command : " << e.what() << endl;
            }
        }
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
}

void ConsoleInterface::printHelp(ostream &output) {
    output << "Help:" << endl;
    output << "You can use the following commands:" << endl;
    output << DISPLAY_CHAR << ": display the current state of the game" << endl;
    output << EMBARK_CHAR << ": embark on a ship" << endl;
    output << DISEMBARK_CHAR << ": disembark from a ship" << endl;
    output << RESET_CHAR << ": reset the game" << endl;
    output << QUIT_CHAR << ": quit the game" << endl;
    output << MENU_CHAR << ": display the menu" << endl;
}

void ConsoleInterface::printLine(ostream &output) {
    for (unsigned i = 0; i < CHARS_PER_LINE; i++) {
        output << LINE_CHAR;
    }
    output << endl;
}

void ConsoleInterface::printRiver(std::ostream &output) {
    for (unsigned i = 0; i < CHARS_PER_LINE; i++) {
        output << RIVER_CHAR;
    }
    output << endl;
}


void ConsoleInterface::printContainer(ostream &output, const Container &container) {
    output << container.getName();
    for (const Person *p: container.getPeople()) {
        output << " " << p->getName();
    }
    output << endl;
}
