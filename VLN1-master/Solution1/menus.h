#ifndef MENUS_H
#define MENUS_H

// Long strings and ASCII art here below \/ \/

std::string MAIN_MENU = "Please use the following commands to interface with this AWESOME DATABASE\n\n\
        add     : Add a record to the database\n\
        order   : Order and dislay the records in the database\n\
        search  : Searches for a scientist\n\
        exit    : Exit the program";

std::string FILTER_MENU = "Enter one of the following commands to order by the corresponding column\n\
along with an ascending(asc) or descending(desc) modifier\n\
        name    : Name\n\
        dob     : Date of birth\n\
        dod     : Date of death\n\
        gender  : Gender\n\n\
Example: \"name desc\"";


#endif // MENUS_H
