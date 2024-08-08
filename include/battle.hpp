/*
	Pokemon
	- Battle Instance

	Written By: Ryan Smith
*/
#pragma once
#include <stdint.h>
#include <vector>

#include "pokemon.hpp"

enum class BattlePosition : uint8_t
{
	User,
	Ally,
	Enemy
};

class BattleInstance
{
	public:
		BattleInstance();
	public:
		void AddPokemon(Pokemon&, BattlePosition);
	private:
		std::vector<Pokemon> UserPokemon;
		std::vector<Pokemon> AllyPokemon;
		std::vector<Pokemon> EnemyPokemon;
};
