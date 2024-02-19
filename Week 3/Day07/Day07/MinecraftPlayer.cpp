#include "MinecraftPlayer.h"


//initialize the fields
//using the member initialization list
MinecraftPlayer::MinecraftPlayer() :
	hearts_(20),
	food_(20),
	armor_(20)
{
}

MinecraftPlayer::MinecraftPlayer(float hearts, float food, float armor)
{
	//use the setters b/c of the protections they provide
	SetHearts(hearts);
	Food(food);
	Armor(armor);
}

void MinecraftPlayer::DoIt(int hearts)
{
	hearts_ = 100;
	float another_name_for_a_variable;
}