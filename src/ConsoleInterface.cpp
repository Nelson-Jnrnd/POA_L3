#include "Headers/ConsoleInterface.hpp"

#include <iostream>

using std::cout;
using std::ostream;
using std::istream;

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

    output << "Welcome to the game!" << std::endl;
    printHelp(output);

    while (true) {
        output << std::endl;
        output << controller->getTurnCount() << "> Enter a command: ";

        std::string inputString;
        getline(input, inputString);

        char command = inputString[0];
        std::string name;
        output << std::endl;
        try {
            switch (command) {
                case DISPLAY_CHAR:
                    printLine(output);
                    printContainer(output, controller->getLeftBank());
                    printLine(output);
                    if (&controller->getBoat().getPosition() ==
                        &controller->getLeftBank()) {
                        printContainer(output, controller->getBoat());
                        printRiver(output);
                        output << std::endl;
                    } else {
                        output << std::endl;
                        printRiver(output);
                        printContainer(output, controller->getBoat());
                    }
                    printLine(output);
                    printContainer(output, controller->getRightBank());
                    printLine(output);
                    break;
                case EMBARK_CHAR:
                case DISEMBARK_CHAR:
                    if (inputString.size() <= 1) {
                        output << "No name given" << std::endl;
                        break;
                    }
                    name = inputString.substr(2);
                    if(command == EMBARK_CHAR) {
                        output << "Embarking..." << std::endl;
                        controller->embark(name);
                    } else {
                        output << "Disembarking..." << std::endl;
                        controller->disembark(name);
                    }
                    break;
                case MOVE_BOAT_CHAR:
                    output << "Moving boat..." << std::endl;
                    controller->moveBoat();
                    break;
                case RESET_CHAR:
                    output << "Resetting..." << std::endl;
                    delete controller;
                    controller = new Controller();
                    break;
                case QUIT_CHAR:
                    output << "Quitting..." << std::endl;
                    delete controller;
                    return;
                case MENU_CHAR:
                    printHelp(output);
                    break;
                default:
                    output << "Unknown command" << std::endl;
                    break;
            }
        }
        catch (const std::invalid_argument &e) {
            output << "Invalid command : " << e.what() << std::endl;
        }
    }
}

void ConsoleInterface::printHelp(ostream &output) {
    output << "Help:" << std::endl;
    output << "You can use the following commands:" << std::endl;
    output << DISPLAY_CHAR << ": display the current state of the game" << std::endl;
    output << EMBARK_CHAR << ": embark on a ship" << std::endl;
    output << DISEMBARK_CHAR << ": disembark from a ship" << std::endl;
    output << RESET_CHAR << ": reset the game" << std::endl;
    output << QUIT_CHAR << ": quit the game" << std::endl;
    output << MENU_CHAR << ": display the menu" << std::endl;
}

void ConsoleInterface::printLine(ostream &output) {
    for (unsigned i = 0; i < CHARS_PER_LINE; i++) {
        output << LINE_CHAR;
    }
    output << std::endl;
}

void ConsoleInterface::printRiver(std::ostream &output) {
    for (unsigned i = 0; i < CHARS_PER_LINE; i++) {
        output << RIVER_CHAR;
    }
    output << std::endl;
}


void ConsoleInterface::printContainer(ostream &output, const Container &container) {
    output << container.getName();
    for (const Person *p: container.getPeople()) {
        output << " " << p->getName();
    }
    output << std::endl;
}
