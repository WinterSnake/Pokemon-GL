/*
	Pokemon

	Written By: Ryan Smith
*/
#include <iostream>
#include <string>
#include "pokemon.hpp"

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	PokemonType attackType = PokemonType::Fire;
	PokemonType defenseType1 = PokemonType::Water;
	PokemonType defenseType2 = PokemonType::None;
	std::string attackName = TypeNameLookupTable[static_cast<uint8_t>(attackType)];
	std::string defenseName1 = TypeNameLookupTable[static_cast<uint8_t>(defenseType1)];
	std::string defenseName2 = "None";
	if (defenseType2 != PokemonType::None)
		defenseName2 = TypeNameLookupTable[static_cast<uint8_t>(defenseType2)];
	float attackMultiplier = calculate_attack_multiplier(attackType, defenseType1, defenseType2);
	std::cout << '[' << attackName << "] type attacking [" << defenseName1 << ',' << defenseName2 << "] type. Multiplier: " << attackMultiplier << '\n';
	return 0;
}
