// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
	Sword, Axe, Spear, Mace
};

//searching a container (vector) for an item (searchTerm)
//true/false? position (index)? looking for the index of the item

int LinearSearch(std::vector<std::string> dinos, std::string searchTerm)
{
	int index = -1;//?? -1 indicates "Not Found"
	for (size_t i = 0; i < dinos.size(); i++)
	{
		if (_stricmp(searchTerm.c_str(), dinos[i].c_str()) == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}


int main()
{
	std::string favDino = "Dino Nuggies";
	std::vector<std::string> dinosaurs{ "T-Rex", "Steggie", "TriC", "Brontz", "Velo", "Pterries" };
	int foundIndex = LinearSearch(dinosaurs, favDino);
	if (foundIndex == -1)
		std::cout << favDino << " was not found. :( \n";
	else
		std::cout << dinosaurs[foundIndex] << "\n";
	/*
		╔═════════╗
		║Searching║
		╚═════════╝

		There are 2 ways to search a vector: linear search or binary search

		CHALLENGE 1:

			write a method to linear search the numbers list.
				The method should take 2 parameters: vector of ints to search, int to search for.
				The method should return -1 if NOT found or the index if found.

			The algorithm:
				1) start at the beginning of the vector
				2) compare each item in the vector to the search item
				3) if found, return the index
				4) if reach the end of the vector, return -1 which means not found

	*/
	std::vector<int> numbers = { 0,1,2,3,4,5,6 };
	int searchNumber = 15;



	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Creating a map  ]

		map<TKey, TValue>  - an associative collection.
			TKey is a placeholder for the type of the keys.
			TValue is a placeholder for the type of the values.

		When you want to create a map variable,
			1) replace TKey with whatever type of data you want to use for the keys
			2) replace TValue with the type you want to use for the values


		[  Adding items to a map  ]

		There are 2 ways to add items to a Dictionaruy:
		1) using the insert method.
		3) using [key] = value
	*/
	std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

	//returns an iterator and a bool. 
	//if the key is already in the map, it will NOT insert it -- the bool will be false.
	auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
	if (inserted.second == false) //meaning not inserted
		std::cout << "The key was already in the map. It was not inserted.\n";
	else
		std::cout << "The key was inserted in the map.\n";

	dorasBackpack[Weapon::Axe] = 3;
	dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map

	//KEYS are unique in a map
	//VALUES are NOT unique in a map

	//type of the keys: string (name of menu items)
	//type of the values: float (price of menu items)

	//1) use the insert method
	std::map<std::string, float> menu;
	auto keyValuePair = std::make_pair("Spaghetti", 25.0F);
	auto wasinserted = menu.insert(keyValuePair);//will NOT overwrite if already in the map
	if (wasinserted.second) //was the item inserted?
	{
		std::cout << "Spaghetti was added.\n";
	}

	//2) use [key] = value
	menu["Kebbah Bi Laban"] = 20.0f;//will overwrite if it's already in the map

	menu["Steak"] = 45.0f;
	menu["Dino Nuggies"] = 55.0f;
	menu["Hot Dog"] = 4.99f;

	float price = menu["Cheez Burgers"];
	std::cout << price << "\n";


	/*
		CHALLENGE 2:

			Create a map that stores names (string) and grades (numbers).
			Call the variable grades.
			Add students and grades to your map.

	*/

	std::vector<std::string> students{ "Anthony", "Austin", "Bryan", "Charles",
	"Colt", "Danah", "Jenna", "Jonathan", "Justin", "Ryan", "Tobey", "Trevor",
	"Abel", "Xavier", "Preston", "Angel", "Dhontay",
	"John C", "Alexandre", "Donell", "Aidan", "Sebastian",
	"Jayden", "Derick", "Timothy", "Jacob", "Devin",
	"Riley", "Corbin", "Fernando", "Matthew", "Ian",
	"Michael", "Thomas", "Chanaya", "Caden", "Derrick",
	"Bryan Z", "Aaron", "Gabriel", "Gyoed", "Kalen", "Trevor" };
	std::map<std::string, double> pg2;
	srand(time(NULL));
	for (auto& student : students)
	{
		pg2[student] = rand() % 10001 / 100.0F;
	}

	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Looping over a map  ]

		You should use a ranged-based for loop when needing to loop over the entire map.

	*/
	for (auto const& [key, val] : dorasBackpack) //requires C++ 20
	{
		switch (key)
		{
		case Weapon::Sword:
			std::cout << "Sword: ";
			break;
		case Weapon::Axe:
			std::cout << "Axe: ";
			break;
		case Weapon::Spear:
			std::cout << "Spear: ";
			break;
		case Weapon::Mace:
			std::cout << "Mace: ";
			break;
		default:
			break;
		}
		std::cout << val << "\n";
	}

	std::cout << "\n\nWelcome to the Bat-Cafe\n";
	for (auto iter = menu.begin(); iter != menu.end(); iter++)
	{
		//iter points to a key-value pair
		std::cout << std::setw(15) << std::left << iter->first << " "; //first is the key
		std::cout << std::setw(5) << iter->second << "\n";//second is the value
	}

	std::cout << "\n\nWelcome to the Bat-Cafe\n";
	for (auto& [menuItem, itemPrice] : menu)
	{
		std::cout << std::setw(15) << std::left << menuItem << " "; 
		std::cout << std::setw(5) << itemPrice << "\n";
	}



	/*
		CHALLENGE 3:

			Loop over your grades map and print each student name and grade.

	*/
	std::cout << "\n\nPG2 Grades for 2402\n";
	for (auto& [name,grade] : pg2)
	{
		std::cout << std::setw(15) << std::left << name << "  ";
		std::cout << std::setw(7) << std::right << grade << "\n";
	}
	std::cout << "\n\n";

	for (auto& keyValuePair : pg2)
	{

	}


	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Checking for a key in a map  ]

		use the find method to check if the key is in the map

		will return map.end() if NOT found.

	*/
	std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
	if (foundIter == dorasBackpack.end()) //meaning it was NOT found
	{
		std::cout << "Dora did not find any maces.\n";
	}
	else
	{
		//can safely grab the value for the key
		std::cout << "Dora found " << foundIter->second << " Maces\n";
	}

	std::string keyToFind = "Dino Nuggies";
	auto foundItem = menu.find(keyToFind);
	if (foundItem != menu.end())//means the key was found
	{
		float nuggiePrice = foundItem->second;// menu[keyToFind];
		std::cout << keyToFind << " costs " << nuggiePrice << ".\n";
		//menu[keyToFind] *= 1.05;
		//OR...use the iterator to update the value
		foundItem->second *= 1.05;
		std::cout << "Now it costs " << menu[keyToFind] << ". Thanks PUTIN!\n\n";
	}
	else
		std::cout << "Sorry. We don't offer " << keyToFind << ".\n";



	/*
		CHALLENGE 5:

			look for a specific student in the map.
			If the student is found, print out the student's grade
			else print out a message that the student was not found

	*/




	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Updating a value for a key in a map  ]

		To update an exisiting value in the map, use the [ ]


	*/
	dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



	/*
		CHALLENGE 6:

			Pick any student and curve the grade (add 5) that is stored in the grades map

	*/
}