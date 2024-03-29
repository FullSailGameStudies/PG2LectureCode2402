﻿// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Superhero.h"

bool postFix(std::string& hero, int& universe)
{
    srand((unsigned int)time(NULL));
    universe = rand() % 10000;
    hero = hero + "-" + std::to_string(universe);
    return universe % 2 == 0;
}

//pass by reference to prevent a COPY of the vector
//add const to prevent the method from MODIFYING my vector
float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

void GetARaise(int& salaryToUpdate)
{
    salaryToUpdate *= 1.03;
}
int GetARaise2(int salaryToUpdate)
{
    salaryToUpdate *= 1.03;
    return salaryToUpdate;
}


void ShowMe(std::string& myName)
{
    std::cout << myName << "\n";
}

void GetTheGradesFor2402(std::vector<float>& course)
{
    srand(time(NULL));
    for (size_t i = 0; i < 10; i++)
    {
        course.push_back((rand() % 10001)/100.0F);
    }
}

void CalcStats(const std::vector<float>& course, float& minGrade, float& maxGrade)
{
    minGrade = maxGrade = course[0];
    for (auto& grade : course)
    {
        if (grade < minGrade) minGrade = grade;
        if (grade > maxGrade) maxGrade = grade;
        //OR...
        //minGrade = std::min(grade, minGrade);
        //maxGrade = std::max(grade, maxGrade);
    }
}

int main()
{
    std::string name = "Batman";
    ShowMe(name);

    int salary = 10000;
    //int& mySalary = salary;
    //mySalary *= 1.03;
    GetARaise(salary);
    std::cout << salary << "\n";

    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    int myUniverse = 0;
    bool isEven = postFix(spider, myUniverse);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector
            3) print the grades after calling the method

    */
    std::vector<float> grades;
    GetTheGradesFor2402(grades);
    std::cout << "\n$_$_$ PG2 2402 $_$_$\n";
    for (auto& grade : grades)
    {
        //setw(#) - sets the width of the next thing being printed
        std::cout << std::setw(10) << std::right << grade << "\n";
    }


    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    highScores.reserve(10);
    printInfo(highScores);//size: 0  capacity: 0
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 10000);
        printInfo(highScores);
    }
    float avg = average(highScores);

    std::cout << highScores[highScores.size() - 1] << "\n";
    highScores.erase(highScores.begin() + 4);
    printInfo(highScores);
    highScores.shrink_to_fit();
    printInfo(highScores);
    std::cout << highScores[highScores.size()-1] << "\n";
    printInfo(highScores);
    


    Superhero notBat("Aquaman");
    std::cout << "I am " << notBat.GetName() << "!\n";


    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. 
                Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */
    float min, max;
    CalcStats(grades, min, max);
    std::cout << "\n\nMin grade: " << min << "\nMax Grade: " << max << "\n\n";





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);
    for (auto i = highScores.begin(); i != highScores.end();)
    {
        if (*i < 2500)
        {
            i = highScores.erase(i);
        }
        else i++;
    }
    //for (size_t i = 0; i < highScores.size();)
    //{
    //    if (highScores[i] < 2500)
    //    {
    //        highScores.erase(highScores.begin() + i);
    //    }
    //    else
    //        i++;
    //}
    ////reverse for loop
    //for (int i = highScores.size() - 1; i >= 0; i--)
    //{
    //    if (highScores[i] < 2500)
    //    {
    //        highScores.erase(highScores.begin() + i);
    //    }
    //}

    print(highScores);


    /*
        INTERMEDIATE LEVEL...
        a way using std::remove_if and a lambda
    highScores.erase(
        std::remove_if(highScores.begin(),
            highScores.end(),
            [](int score) { return score < 2500; }),
        highScores.end());
    */


    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}