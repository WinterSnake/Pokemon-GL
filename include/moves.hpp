#pragma once
#include <array>
#include <string>
#include "pokemon.hpp"

constexpr size_t MOVES_COUNT = 6;
const std::array<const MoveInfo, MOVES_COUNT> POKEMON_MOVES = {{
	{
		.Name = "Tackle",
		.Type = ElementType::Normal,
		.Category = MoveInfo::Category::Physical,
		.PP = 35, .MaxPP = 56,
		.Power = 35, .Accuracy = 100,
	},
	{
		.Name = "Absorb",
		.Type = ElementType::Grass,
		.Category = MoveInfo::Category::Special,
		.PP = 25, .MaxPP = 40,
		.Power = 20, .Accuracy = 100,
	},
	{
		.Name = "Scratch",
		.Type = ElementType::Normal,
		.Category = MoveInfo::Category::Physical,
		.PP = 35, .MaxPP = 56,
		.Power = 35, .Accuracy = 100,
	},
	{
		.Name = "Growl",
		.Type = ElementType::Normal,
		.Category = MoveInfo::Category::Status,
		.PP = 40, .MaxPP = 64,
		.Power = 0, .Accuracy = 100,
	},
	{
		.Name = "Tail Whip",
		.Type = ElementType::Normal,
		.Category = MoveInfo::Category::Status,
		.PP = 40, .MaxPP = 64,
		.Power = 0, .Accuracy = 100,
	},
	{
		.Name = "Acid",
		.Type = ElementType::Poison,
		.Category = MoveInfo::Category::Special,
		.PP = 30, .MaxPP = 48,
		.Power = 40, .Accuracy = 100,
	},
}};

const MoveInfo* MOVE_TACKLE    = &POKEMON_MOVES[0];
const MoveInfo* MOVE_ABSORB    = &POKEMON_MOVES[1];
const MoveInfo* MOVE_SCRATCH   = &POKEMON_MOVES[2];
const MoveInfo* MOVE_GROWL     = &POKEMON_MOVES[3];
const MoveInfo* MOVE_TAIL_WHIP = &POKEMON_MOVES[4];
const MoveInfo* MOVE_ACID      = &POKEMON_MOVES[5];
