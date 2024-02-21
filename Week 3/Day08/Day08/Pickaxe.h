#pragma once
#include <vector>
#include <string>
#include <iostream>

class Pickaxe
{
public:
	void AddEnchantment(std::string enchantment)
	{
		enchantments_.push_back(enchantment);
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
	std::vector<std::string> enchantments_;
};

