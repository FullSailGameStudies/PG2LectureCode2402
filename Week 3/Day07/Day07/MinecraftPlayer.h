#pragma once

class MinecraftPlayer
{
	//What can the object DO? (methods)
	//What describes the object? (data/fields)

private:
	//FIELDS (data of the class)
	//GENERALLY, you make them private until they have to be seen by other classes
	float hearts_, food_, armor_;

private:

	void DoIt(int hearts)
	{
		hearts_ = 100;
		float anotherVariable;
	}
};

