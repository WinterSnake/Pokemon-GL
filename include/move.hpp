/*
	Pokemon
	- Move Data

	Written By: Ryan Smith
*/
#pragma once
#include <stdint.h>
#include <string>

struct Move
{
	public:
		const std::string Name;
		const ElementType Type;
		enum class CategoryType : uint8_t
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

const std::array<Move, 2> MoveList = {
	(Move){
		.Name = "Absorb",
		.Type = ElementType::Grass,
		.Category = Move::CategoryType::Special,
		.PP = 25, .MaxPP = 40,
		.Power = 20, .Accuracy = 100
	},
	(Move){
		.Name = "Acid",
		.Type = ElementType::Poison,
		.Category = Move::CategoryType::Special,
		.PP = 30, .MaxPP = 48,
		.Power = 40, .Accuracy = 100
	},
};
