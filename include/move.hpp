/*
	Pokemon
	- Move Data

	Written By: Ryan Smith
*/
#pragma once
#include <stdint.h>
#include <string>
#include "element.hpp"

// Base move info
struct MoveInfo
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

// Move counter for pokemon move sets
struct MoveBattle
{
	public:
		const MoveInfo* Info;
		uint8_t PP;
		uint8_t MaxPP;
};
