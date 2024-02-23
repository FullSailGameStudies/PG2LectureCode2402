// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "static.h"
#include <memory>

/*
Nested class
Abstract class
Static members
Final members
Friends
*/

int main()
{

    /*
        ╔════════════════════╗
        ║  Static Variables  ║
        ╚════════════════════╝


    */
    for (size_t i = 0; i < 10; i++)
    {
        demo();
    }
    std::cout << "\n\n";



    /*
        ╔══════════════════╗
        ║  Static Members  ║
        ╚══════════════════╝

        When calling a non-static method on a class, you must use a variable of that class.
        That's because the variable is passed in as the 'this' parameter.

        Static methods do not have a 'this' parameter therefore you call them on the 
        class name itself.

        That's also why static methods cannot access non-static members.

    */
    std::unique_ptr<Car> otherCar = nullptr;
    {
        Car myRide(1988);
        Car::reporting();
        myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'
    
        //Car* pCar = &myRide;
        std::unique_ptr<Car> pCar = std::make_unique<Car>(2025);
        std::cout << "\nPointer to myRide: " << pCar << "\n";
        pCar->vehicleInfo();
    
        otherCar = std::move(pCar); //copy the memory location to another pointer variable

        pCar->vehicleInfo();
        //delete pCar;
        //pCar = nullptr;
        //otherCar = nullptr;
    
    }
    if (otherCar != nullptr)
    {
        otherCar->vehicleInfo();
    }
    /*
    
        CHALLENGE:
        Add a static method to the Car class that returns an instance of the Car class.
    
    */
}