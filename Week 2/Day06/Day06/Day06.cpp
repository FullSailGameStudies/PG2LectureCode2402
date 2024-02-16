﻿// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include "Day06.h"


enum class Weapon
{
    Sword, Axe, Spear, Mace
};


void PrintGrades(std::map<std::string, double>& grades)
{
    std::cout << "\nWelcome to the DCU\n";
    for (auto& [hero, grade] : grades)
    {
        std::cout << std::setw(8) << std::left << hero << " ";
        std::cout << std::setw(7) << grade << "\n";
    }
}

int main()
{

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Removing a key and its value from a map  ]

        erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
        erase(key) -- returns the # of items removed

    */
    std::map<Weapon, int> dorasbackpack;
    auto inserted = dorasbackpack.insert(std::make_pair(Weapon::Sword, 5));
    dorasbackpack[Weapon::Axe] = 3;

    size_t numberRemoved = dorasbackpack.erase(Weapon::Sword);
    if (numberRemoved > 0)
        std::cout << "The Swords were removed.\n";
    else
        std::cout << "Sword was not found in the map.\n";

    std::map<Weapon, int>::iterator found = dorasbackpack.find(Weapon::Axe);
    if (found != dorasbackpack.end())
    {
        dorasbackpack.erase(found);
        std::cout << "The Axes were removed.\n";
    }
    else
        std::cout << "Axe was not found in the map.\n";





    /*
        CHALLENGE 1:

                    print the students and grades below
                        use std::setw and std::left and std::right to format the output
                    ask for the name of the student to drop from the grades map
                        use std::getline to get the user's input
                    remove the student from the map
                    print message indicating what happened
                    if not found print an error message
                    else print the map again and print that the student was removed


    */
    srand((unsigned int)time(NULL));
    std::map<std::string, double> grades;
    grades["Bruce"] = rand() % 101;
    grades["Dick"] = rand() % 101;
    grades["Diana"] = rand() % 101;
    grades["Alfred"] = rand() % 101;
    grades["Clark"] = rand() % 101;
    grades["Arthur"] = rand() % 101;
    grades["Barry"] = rand() % 101;

    while (true)
    {
        PrintGrades(grades);
        std::cout << "Name of the student to drop: ";
        std::string name;
        std::getline(std::cin, name);
        if (name.size() == 0) break;

        std::cout << "Dropping " << name << " from the DCU\n";
        size_t result = grades.erase(name);
        if (result > 0)
        {
            std::cout << name << " was removed from the DCU.\n";
            auto iterator = grades.find(name);
            if (iterator == grades.end())
                std::cout << "VERIFIED!\n";
            else
                std::cout << "Something went horribly wrong.\n";
        }
        else
            std::cout << name << " was not found in the DCU.\n";
    }
}