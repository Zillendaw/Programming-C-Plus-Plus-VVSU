#pragma once

#include <sstream>

enum PersonCategory
{
    CHILD,
    TEEN,
    ADULT
};

struct Person 
{
    std::string firstname;
    std::string sirname; 
    int birthyear;
    PersonCategory category;
};

PersonCategory getPersonCategory(Person person);
void savePersonToFile(Person person);
