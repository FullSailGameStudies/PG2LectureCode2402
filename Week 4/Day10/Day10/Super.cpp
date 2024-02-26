#include "Super.h"
#include <sstream>

Super::Super(std::string csvData, char delimiter)
{
	deserialize(csvData, delimiter);
}

void Super::serialize(std::ostream& outputFile, char delimiter)
{
	//write the data of the Super to the outputfile separated by the delimiter
	outputFile << name_ << delimiter << secret_ << delimiter << age_;
}

void Super::deserialize(std::string csvData, char delimiter)
{
	std::stringstream heroStream(csvData);
	std::string ageString;
	std::getline(heroStream, name_, delimiter);
	std::getline(heroStream, secret_, delimiter);
	std::getline(heroStream, ageString, delimiter);
	age_ = std::stoi(ageString);
}
