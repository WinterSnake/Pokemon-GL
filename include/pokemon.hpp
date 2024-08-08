/*
	Pokemon
	- Pokemon

	Written By: Ryan Smith
*/
#pragma once
#include <array>
#include <string>

#include "generated/element.hpp"

/* Move Data */
// Structure for move data generated from moves
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

// Structure for moves learned by pokemon based on certain criteria
struct MoveLearn
{
	public:
		const MoveInfo* Info;
		uint8_t Level;
};

// Structure for moves attached to a pokemon in the party
struct MoveBattle
{
	public:
		const MoveInfo* Info;
		uint8_t PP;
};

/* Pokemon Data */
constexpr size_t BATTLE_MOVES_COUNT = 4;

// Structure for pokemon data generated from species
struct PokemonInfo
{
	public:
		const std::string Name;
		const std::array<ElementType, 2> Elements;
		const MoveLearn* Moveset;
		const size_t MovesetSize;
};

// Structure for pokemon in party
class Pokemon
{
	public:
		static Pokemon FromInfo(const PokemonInfo*, uint8_t);
	public:
		const PokemonInfo* Info;
		std::array<MoveBattle, BATTLE_MOVES_COUNT> Moves;
};
