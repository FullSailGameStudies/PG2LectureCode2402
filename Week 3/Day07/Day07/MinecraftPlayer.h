#pragma once

class MinecraftPlayer
{
	//What can the object DO? (methods)
	//What describes the object? (data/fields)

public:
	// ctors (constructors)
	// IFF you do not have any ctor in your code,
	// the compiler will give you an empty default ctor
	// If you provide any ctor of your own,
	// the compiler ctor is not created
	MinecraftPlayer();//default ctor (no parameters)

	MinecraftPlayer(float hearts, float food, float armor);

public:
	//getters (accessors) of your fields
	float GetHearts() const	{ return hearts_; }
	float Food() const { return food_; }
	float Armor() const { return armor_; }

	//setters (mutators) of your fields

	/// <summary>
	/// Sets the heart level of the minecraft player.
	/// Valid range: 0-20
	/// </summary>
	/// <param name="hearts"></param>
	void SetHearts(float hearts) {
		if(hearts >= 0 and hearts <= 20)
			hearts_ = hearts;
	}
	/// <summary>
	/// Sets the food level of the Minecraft player.
	/// Valid range: 0-20
	/// </summary>
	/// <param name="food"></param>
	void Food(float food)//an overload of the Food method
	{
		if (food >= 0 and food <= 20)
			food_ = food;
	}

	void Armor(float newArmorLevel)
	{
		if (newArmorLevel >= 0 and newArmorLevel <= 20)
			armor_ = newArmorLevel;
	}


private:
	//FIELDS (data of the class)
	//GENERALLY, you make them private until they have to be seen by other classes
	float hearts_, food_, armor_;

private:

	void DoIt(int hearts);
};

