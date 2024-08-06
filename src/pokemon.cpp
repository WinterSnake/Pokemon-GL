/*
	Pokemon
	- Pokemon

	Written By: Ryan Smith
*/
#include "pokemon.hpp"

/* Moves */
Move::Move(const std::string name, const ElementType type, Move::CategoryType category)
	: Name(name), Type(type), Category(category) {}


float calculate_attack_multiplier(ElementType attack, ElementType defenseType1, ElementType defenseType2)
{
	float result = TypeAdvantageLookupTable[static_cast<uint8_t>(attack)][static_cast<uint8_t>(defenseType1)];
	if (defenseType2 != ElementType::None)
		return result * TypeAdvantageLookupTable[static_cast<uint8_t>(attack)][static_cast<uint8_t>(defenseType2)];
	return result;
}
