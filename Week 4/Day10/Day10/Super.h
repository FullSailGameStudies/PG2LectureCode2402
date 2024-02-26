#pragma once
#include <string>
#include <fstream>

class Super
{
public:
	Super(std::string name, std::string secret, int age) :
		name_(name), secret_(secret), age_(age)
	{	}

	Super(std::string csvData, char delimiter);

	std::string Name() const { return name_; }
	std::string Secret() const { return secret_; }
	int Age() const { return age_; }

	void serialize(std::ostream& outputFile, char delimiter);
	void deserialize(std::string csvData, char delimiter);

private:
	std::string name_, secret_;
	int age_;
};

