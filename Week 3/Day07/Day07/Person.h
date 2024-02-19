#pragma once
#include <string>

class Person
{

public:
	void ItsMyBirthday();

	int Age() const { return age_; }
	void Age(int newAge) {
		if (newAge >= 0 && newAge <= 120)
			age_ = newAge;
	}

	std::string Name() const { return name_; }
	void Name(std::string newName) {
		if (newName.size() > 0 && newName.size() < 35)
			name_ = newName;
	}

private:
	int age_;
	std::string name_;
};

