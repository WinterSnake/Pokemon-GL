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

struct PokemonInfo
{
	public:
		const std::string Name;
		const std::array<ElementType, 2> Elements;
};

constexpr size_t BATTLE_MOVES_COUNT = 4;
class Pokemon
{
	public:
		const PokemonInfo* Info;
		std::array<MoveBattle, BATTLE_MOVES_COUNT> Moves;
};
