// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Super.h"



/*
	╔══════════╗
	║ File I/O ║
	╚══════════╝

	3 things are required for File I/O:
	1) Open the file
	2) read/write to the file
	3) close the file



*/
int main()
{
	std::cout << "Hello PG2!\n";

	/*

		╔════════════════╗
		║ write csv data ║
		╚════════════════╝

		[  Open the file  ]
		[  Write to the file  ]
		[  Close the file  ]

		you need the path to the file
			use full path ( drive + directories + filename )
			or use relative path ( directories + filename )
			or current directory ( filename )

		Make sure to separate the data in the file with a delimiter.
		The delimiter is important because it is used
			to separate the data when reading the file back in.


		Lecture code: set a filePath variable, open an output file, write some csv data to it
	*/

	std::string fileName = "2402.csv";
	std::string filePath = "";// C:\\temp\\2402\\";
	std::string finalPath = filePath + fileName;

	std::ofstream outFile(finalPath); //1) attempt to open the file
	char delimiter = '^';
	if (outFile.is_open())
	{
		//2) write to the file
		//looks like working with cout
		outFile << "Tiny horses are SOOOO cute." << delimiter <<
			5 << delimiter << true << delimiter << 13.7;
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	//3) close the file
	outFile.close();


	/*

		╔═══════════════╗
		║ read csv data ║
		╚═══════════════╝

		[  Open the file  ]
		[  read the file  ]
		[  Close the file  ]

		Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
	*/

	std::ifstream inFile(finalPath);
	if (inFile.is_open())
	{
		std::string line;
		std::getline(inFile, line);//by default, it will read up until the first \n
		std::cout << line << "\n";

		//we need a stringstream
		std::stringstream lineStream(line);
		std::string data;

		std::getline(lineStream, data, delimiter);
		std::cout << data << "\n";

		std::getline(lineStream, data, delimiter);
		int number = std::stoi(data);
		std::cout << number << "\n";

		std::getline(lineStream, data, delimiter);
		bool isTrue = std::stoi(data) == 1;
		std::cout << isTrue << "\n";

		std::getline(lineStream, data, delimiter);
		double bigNum = std::stod(data);
		std::cout << bigNum << "\n";
	}
	else
	{
		std::cout << finalPath << " could not be opened.\n";
	}
	inFile.close();



	/*

		╔═════════════════════╗
		║ parsing csv strings ║
		╚═════════════════════╝

		use getline on a string stream instead of a file stream

		Lecture code:
			using the line read in above, use a stringstream to split the line using getline.
			store the separate items in a vector
			parse each item in the vector to an appropriate variable.


	*/





	/*

		CHALLENGE:

		Parse the multi csv string (below) to get the data.
		NOTE: the data is a collection of object data.
		There are multiple delimiters.
		Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
		Then, separate the object csv data on objectSeparator to get the details of the object.

		EX: hero#hero#hero   each hero is separated by a #
			name^secret^age  the details of each hero is separated by a ^

	*/
	std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
	char collectionSeparator = '#';
	char objectSeparator = '^';

	//read each hero (some kind of loop)
	//	read each piece of data from the hero (loop?)
	//		create a Super object and store the data in it
	//		store the super object in the vector
	//print the vector

	std::stringstream multiStream(multi);
	std::string heroString;
	std::vector<Super> DC;
	while (std::getline(multiStream, heroString, '#'))
	{
		std::cout << heroString << "\n";

		std::stringstream heroStream(heroString);
		std::string name, secret, ageString;
		std::getline(heroStream, name, '^');
		std::getline(heroStream, secret, '^');
		std::getline(heroStream, ageString, '^');

		Super hero(name, secret, std::stoi(ageString));
		DC.push_back(hero);
	}

	std::cout << "\n\nDC Universe\n";
	for (auto& hero : DC)
	{
		std::cout << "Hello citizen! I am " << hero.Name() << " (aka " << hero.Secret() << ").";
		std::cout << " I am " << hero.Age() << " years old!!\n";
	}

	std::string dcFile = "DC.csv";
	finalPath = filePath + dcFile;
	std::ofstream dcSaveFile(finalPath);
	if (dcSaveFile.is_open())
	{
		for (auto& hero : DC)
		{
			hero.serialize(dcSaveFile, '*');
			dcSaveFile << "\n";
		}
	}
	else {
		std::cout << "Could not open file " << finalPath << "\n";
	}
	dcSaveFile.close();


	std::cout << "\n\nDC Serialized to cout\n";
	for (auto& hero : DC)
	{
		hero.serialize(std::cout, ':');
		std::cout << "\n";
	}
}