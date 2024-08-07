/*
	Pokemon
	- Pokemon

	Written By: Ryan Smith
*/
#pragma once
#include <array>
#include <string>

#include "element.hpp"
#include "move.hpp"

struct PokemonSpecies
{
	public:
		std::string Name;
		std::array<ElementType, 2> Elements;

	private
		MoveSet* Moveset;
};
