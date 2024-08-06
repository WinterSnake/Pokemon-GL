/*
	Pokemon
	- Pokemon

	Written By: Ryan Smith
*/
#pragma once
#include <string>

#include "element.hpp"
#include "move.hpp"

class Pokemon
{
	public:
		std::string Name;
		ElementType Types[2];
	public:
		float calculate_attack_multiplier(ElementType attackType);
		float calculate_defense_multipler(ElementType attackType);
};
