#ifndef MENUS_H
#define MENUS_H

// Long strings and ASCII art here below \/ \/

std::string MAIN_MENU = "Please use the following commands to interface with this AWESOME DATABASE\n\n\
        addScientist  : Add a scientist to the database\n\
        addComputer   : Add a computer to the database\n\
        order         : Order and dislay the records in the database\n\
        search        : Searches for a scientist\n\
        exit          : Exit the program";

std::string FILTER_MENU = "Enter one of the following integers to order by the corresponding column.\n\
        1     : Name\n\
        2     : Date of birth\n\
        3     : Date of death\n\
        4     : Gender\n\ Press 1 if you want to sort ascending and 2 if you want to sort descending\n\n\
    Example: \"1 1\"";


#endif // MENUS_H
