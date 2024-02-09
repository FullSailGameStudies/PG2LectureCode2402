#pragma once
#include <string>

class Superhero
{
public:
	Superhero(std::string name) : name_(name)
	{	}

	std::string GetName() const;

private:
	std::string name_;
};

