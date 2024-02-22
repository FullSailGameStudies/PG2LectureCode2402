#pragma once
#include <vector>
#include <string>
#include <iostream>

class Pickaxe
{
public:
	//static methods can ONLY see static members
	// there is NO hidden parameter for "this"
	static void PickaxeDebugger()
	{
		std::cout << "Number of pickaxes made: " << numberOfPickaxes << "\n";
		//this->Tooltip();
	}
	
	//non-static methods can see non-static AND static members
	//there is a HIDDEN parameter called "this"  (Pickaxe* this)
	void AddEnchantment(std::string enchantment)
	{
		//how does it figure out which vector to add it to? picky or goldenBoy?
		enchantments_.push_back(enchantment);
		Tooltip();
	}
	Pickaxe operator+(const Pickaxe& other)
	{
		Pickaxe newPickaxe;
		for (auto& enchantment : enchantments_)
		{
			newPickaxe.enchantments_.push_back(enchantment);
		}
		for (auto& enchantment : other.enchantments_)
		{
			newPickaxe.enchantments_.push_back(enchantment);
		}
		return newPickaxe;
	}
	void Tooltip()
	{
		for (auto& enchantment : enchantments_)
		{
			std::cout << enchantment << "\n";
		}

	}

private:
	std::vector<std::string> enchantments_; //non-static fields
	static int numberOfPickaxes;//ALL pickaxes share this variable
};

