#include "Bots.h"
#include <iostream>

//This is for the DEFINITIONS
void Bots::MowerBot()
{
    std::cout << "MOWING...\n";
    std::cout << "DONE! return to charger.\n";
}

void Bots::CleaningBot(std::string roomToClean)
{
    std::cout << "Cleaning " << roomToClean << "...\n";
    std::cout << "DONE! return to charger.\n";
}

//the value for recipe is COPIED into it from whoever calls it
std::string Bots::CookingBot(std::string recipe)
{
    std::cout << "Cooking " << recipe << "...\n";
    std::cout << "DONE! return to charger.\n";
    return "I made you a burger instead.";
}
