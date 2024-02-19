#include "Person.h"
#include <iostream>

void Person::ItsMyBirthday()
{
	//age_++;
	Age(age_ + 1);
	std::cout << "It's my birthday! I am " << age_ << " years old today! Let's have cake!!\n";
}
