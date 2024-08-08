/*
	Pokemon
	- Pokemon

	Written By: Ryan Smith
*/
#pragma once
#include <array>
#include <string>

#include "element.hpp"

/* Move Data */
struct MoveInfo
{
	public:
		const std::string Name;
		const ElementType Type;
		enum class Category : uint8_t
		{
			Physical,
			Special,
			Status,
		} const Category;
		uint8_t PP;
		uint8_t MaxPP;
		uint8_t Power;
		uint8_t Accuracy;
};

/* Pokemon Data */
constexpr size_t BATTLE_MOVES_COUNT = 4;

struct PokemonInfo
{
	public:
		const std::string Name;
		const std::array<ElementType, 2> Elements;
};

class Pokemon
{
	public:
		const PokemonInfo* Info;
};
