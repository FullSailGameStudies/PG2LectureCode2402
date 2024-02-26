#include "Super.h"

void Super::serialize(std::ostream& outputFile, char delimiter)
{
	//write the data of the Super to the outputfile separated by the delimiter
	outputFile << name_ << delimiter << secret_ << delimiter << age_;
}
