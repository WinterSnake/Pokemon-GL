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
	ElementType attack   = ElementType::Fighting;
	ElementType defense1 = ElementType::Bug;
	ElementType defense2 = ElementType::Ghost;
	std::string typeNames[3] = {
		ElementNameLookupTable[ELEMENT_VALUE(attack)],
		ElementNameLookupTable[ELEMENT_VALUE(defense1)],
		ElementNameLookupTable[ELEMENT_VALUE(defense2)],
	};
	float multiplier = ElementMultiplierLookupTable[ELEMENT_VALUE(attack)][ELEMENT_VALUE(defense1)][ELEMENT_VALUE(defense2)];
	std::cout << "Attack[" << typeNames[0] << "] vs Creature[" << typeNames[1] << ',' << typeNames[2] << "] = " << multiplier << '\n';
	return 0;
}
