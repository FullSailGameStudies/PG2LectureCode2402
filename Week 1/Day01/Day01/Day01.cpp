// Day01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "Calculator.h"
#include "Bots.h"

int AddOne(int localNumber)
{
	return localNumber + 1;
}

void print(const std::vector<std::string>& names)
{
	std::cout << "----NAMES----\n";
	int index = 1;
	for (std::string name : names)
		std::cout << index++ << ". " << name << "\n";
}

//return type. if nothing is returned, use "void" else use the TYPE of the data being returned


int main()
{
	Bots maintenanceBots;
	maintenanceBots.MowerBot();

	std::string room = "Kitchen";
	maintenanceBots.CleaningBot(room);

	std::string foodToEat = "spaghetti";
	std::string plate = maintenanceBots.CookingBot(foodToEat);//foodToEat is COPIED to recipe
	std::cout << "Thank you cookingBot. I'm going to enjoy my meal of " << plate << "\n";
	/*
	  Calling a method
		use the methods name.
		1) if the method needs data (i.e. has parameters), you must pass data to the method that matches the parameter types
		2) if the method returns data, it is usually best to store that data in a variable on the line where you call the method.

	*/

	/*
		╔══════════════════════════╗
		║Parameters: Pass by Value.║
		╚══════════════════════════╝

		Copies the value to a new variable in the method.

		For example, the AddOne method has a parameter called localNumber. localNumber is a variable that is local ONLY to the method.
		The value of the variable in main, number, is COPIED to the variable in AddOne, localNumber.

	*/
	int number = 5;
	int plusOne = AddOne(number);

	//Examples:
	//  calling a static method, prefix with the class name...
	double factor = Calculator::mult(5, 3);

	//calling a non-static method, use the variable...
	Calculator t1000;
	int diff = t1000.minus(7, 2);


	/*
		CHALLENGE #1:

			Add an isEven method to the calculator.
			It should take 1 parameter and return a bool.

			Call the method on the t1000 calculator instance and print the results.

	*/
	bool amIEven = t1000.isEven(number);



	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝

		[  Creating a vector  ]

		vector<T>  - the T is a placeholder for a type.

		When you want to create a vector variable, replace T with whatever type of data you want to store in the vector.



		[  Adding items to a vector  ]

		There are 2 ways to add items to a vector:
		1) on the initializer.
		2) using the push_back(item) method.
	*/
	std::vector<std::string> names{ "Batman", "Bruce Wayne", "The Best" };
	names.push_back("The Greatest Detective");
	names.push_back("The Bat");
	names.push_back("The Joker");
	names.push_back("Bane");
	names.push_back("Poison Ivy");


	std::vector<std::string> menu{ "Waffles", "Pancakes" };
	menu.push_back("Glue?");
	menu.push_back("Rocky Road Ice Cream");
	menu.push_back("Waffles");
	menu.push_back("Spicy Ramen");

	std::string lunch = menu[1];//store "Pancakes" in the variable

	std::cout << "\n\nChez PG2\n";
	//first index: 0
	//last index: size()-1
	for (int i = 0; i < menu.size(); i++)
	{
		std::string menuItem = menu.at(i);//copies the string
		std::cout << menuItem << "\n";
	}

	std::cout << "\n\nChez PG2 (iterators)\n";
	for (auto i = menu.begin(); i != menu.end(); i++)
	{
		std::string menuItem = *i;//* dereferences the pointer
		std::cout << menuItem << "\n";
	}

	std::cout << "\n\nChez PG2 (range-based)\n";
	//& creates a reference variable
	for (auto& menuItem : menu)//points menuItem to the actual string. DOES NOT copy
	{
		std::cout << menuItem << "\n";
	}


	menu.erase(menu.begin() + 2);//needs an iterator to erase
	menu.erase(menu.end() - 1);//removes the last item
	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝

		[  Looping over a vector  ]

		You can loop over a vector with a for loop with iterators or a range-based for loop.

	*/
	// begin() -- returns an iterator pointing to the first element
	// end() – returns an iterator pointing to the element AFTER the last element
	std::cout << "--- for loop:\n";
	for (size_t i = 0; i < names.size(); i++)
	{
		std::cout << names[i] << "\n";
	}
	std::cout << "\n\n";


	std::cout << "--- for loop with iterators:\n";
	for (auto i = names.begin(); i != names.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	std::cout << "\n\n";

	std::cout << "--- Range-based for loop:\n";
	for (auto& name : names)
		std::cout << name << std::endl;
	std::cout << "\n\n";






	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝

		[  Removing from a vector  ]

		clear() - removes all elements from the vector
		erase(position) - removes the element at the position
		erase(starting position, ending position) - removes a range of elements. the end position is not erased.

	*/
	print(names);

	std::cout << "\nerase the 5th item (" << names[4] << ")\n";
	names.erase(names.begin() + 4); //the position is the 4th item AFTER the first element. in other words, the 5th item.
	print(names);

	std::cout << "\nerase the 3rd item (" << names[2] << ") up to but not including the 5th item (" << names[4] << ")\n";
	std::vector<std::string>::iterator start = names.begin() + 2;//start at the 3rd item.
	std::vector<std::string>::iterator end = start + 2;//ends at the 5th item. 
	names.erase(start, end);//erases elements 3 and 4 but stops at the 5th.
	print(names);


	names.clear();
	std::cout << "\nclear all elements\n";
	print(names);


	/*
	  CHALLENGE #2:

		  Create a vector that stores floats. Call the variable grades.
		  Add a few grades to the grades vector.

	  */

	  /*
		  CHALLENGE #3:

			  loop over the grades vector and print out each grade

	  */
	  /*

		  CHALLENGE #4:

			  Using the vector of grades you created.
			  Remove the last item in the vector.
			  Print the grades.

	  */





  /*
	  BOSS CHALLENGE:

		  1) Add an Average method to the calculator class to calculate the average of a vector.
		  2) Call the Average method on the t1000 variable and pass your grades vector to the method.
		  3) print the average that is returned.

  */

}
