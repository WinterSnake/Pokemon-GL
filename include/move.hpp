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
	public:
		Move(const std::string, const ElementType, const CategoryType, uint8_t, uint8_t);
};

const std::array<Move, 2> MoveList = {
	Move("Absorb",
		ElementType::Grass,
		Move::CategoryType::Special,
		25, 40,   // PP | Max PP
		20, 100,  // Power | Accuracy
	),
	Move("Acid",
		ElementType::Poison,
		Move::CategoryType::Special,
		30, 48,   // PP | Max PP
		40, 100,  // Power | Accuracy
	),
};
