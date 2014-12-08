#include "consoleui.h"
#include <iostream>
#include <string>
#include "menus.h"
#include <stdexcept>
#include <sstream>

ConsoleUI::ConsoleUI() {
    scienceService = ScienceService();
}

ConsoleUI::~ConsoleUI() {
}

int ConsoleUI::start() {
    // REPL
    while(true) {
        int response = respondToMessage();
        if( response == 0)
        {
            return 0;
        }
    }

    return 1;
}

void ConsoleUI::clear() {
    // Not pretty, but it is platform independant
    std::cout << std::string( 100, '\n' );
}

void ConsoleUI::waitForPrompt() {
    std::cout << "\nPress enter to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

int ConsoleUI::respondToMessage() {

    std::cout << MAIN_MENU << std::endl;

    std::string userRequest;
    std::cin >> userRequest;

    try {
        // Handle all available commands and throw error on unknown ones
        if(userRequest.find("add") != std::string::npos) {
            clear();
            Scientist additionalScientist = Scientist();
            std::cout << "Enter the name of the scientist: ";
            std::cin.ignore();
            std::getline(std::cin, additionalScientist.name);
            clear();
            std::cout << "Enter the date of birth of the scientist: ";
            std::cin >> additionalScientist.dateOfBirth;
            clear();
            std::cout << "Enter the date of death of the scientist: ";
            std::cin >> additionalScientist.dateOfDeath;
            clear();
            std::cout << "Enter the gender of the scientist: ";
            std::cin >> additionalScientist.gender;
            scienceService.addScientist(additionalScientist);
            clear();
        } else if(userRequest.find("search") != std::string::npos) {
            clear();
            std::string searchTerm = "";
            std::cout << "Enter the search term: ";
            std::cin.ignore();
            std::getline(std::cin,searchTerm);
            clear();
            Scientist* searchResult = scienceService.search(searchTerm);
            if(searchResult) {
                std::cout << "Scientist found!!" << std::endl;
                std::cout << "Name:\t\tDateOfBirth:\tDateOfDeath:\tGender:\n";
                std::cout << searchResult->name << "\t" << searchResult->dateOfBirth << "\t\t" << searchResult->dateOfDeath << "\t\t" << searchResult->gender << std::endl;
            } else {
                std::cout << "No results found for the term: " << searchTerm << std::endl;
            }
            waitForPrompt();
            clear();
        } else if(userRequest.find("order") != std::string::npos) {
            clear();
            std::string filterCol = "";
            std::string filterMod = "";
            std::cout << FILTER_MENU << std::endl;
            std::cin >> filterCol >> filterMod;
            clear();
            std::list<Scientist> l = scienceService.getScientistsOrderedBy(filterCol,filterMod);
            std::cout << "Name:\t\tDateOfBirth:\tDateOfDeath:\tGender:\n";
            for(std::list<Scientist>::iterator iter = l.begin(); iter != l.end(); iter ++) {
                std::cout << iter->name << "\t" << iter->dateOfBirth << "\t\t" << iter->dateOfDeath << "\t\t" << iter->gender << std::endl;
            }
            waitForPrompt();
            clear();
        } else if (userRequest.find("exit") != std::string::npos) {
            return 0;
        } else {
            throw std::runtime_error( userRequest + " is not a valid command.");
        }
    } catch(std::runtime_error e) {
        clear();
        std::cout << "Command caused an error: " << e.what() << std::endl;
        std::cout << "Please try another command" << std::endl;
        waitForPrompt();
        clear();
    }

    return 1;
}

