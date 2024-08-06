/*
	Pokemon
	- Element Data

	Initial Chart: https://pokemondb.net/type
	Links of type advantage changes:
		- https://gamerant.com/pokemon-changes-needed-balance-type-chart/
		- https://gamerant.com/pokemon-go-type-advantages-best-worst/
		- https://www.reddit.com/r/pokemon/comments/13rwc2a/how_i_would_change_pok%C3%A9mon_types_and_some_other/
		- https://www.reddit.com/r/pokemon/comments/c2o843/how_would_you_change_the_pok%C3%A9mon_type/
		- https://community.pokemon.com/en-us/discussion/5834/you-can-make-one-change-to-the-type-chart-what-do-you-change/p2

	Written By: Ryan Smith
*/
#pragma once
#include <stdint.h>
#include <array>
#include <string>

#define ELEMENT_COUNT 18
enum class ElementType : uint8_t
{
	Normal   =   0,
	Fire     =   1,
	Water    =   2,
	Electric =   3,
	Grass    =   4,
	Ice      =   5,
	Fighting =   6,
	Poison   =   7,
	Ground   =   8,
	Flying   =   9,
	Psychic  =  10,
	Bug      =  11,
	Rock     =  12,
	Ghost    =  13,
	Dragon   =  14,
	Dark     =  15,
	Steel    =  16,
	Fairy    =  17,
	None     = 255,
};

float calculate_attack_multiplier(ElementType attack, ElementType defenseType1, ElementType defenseType2);

#define ELEMENT_NAME_LOOKUP(type) static_cast<uint8_t>(ElementType::type)
const std::array<const std::string, ELEMENT_COUNT> TypeNameLookupTable = {{
	[ELEMENT_NAME_LOOKUP(Normal)]   = "Normal",
	[ELEMENT_NAME_LOOKUP(Fire)]     = "Fire",
	[ELEMENT_NAME_LOOKUP(Water)]    = "Water",
	[ELEMENT_NAME_LOOKUP(Electric)] = "Electric",
	[ELEMENT_NAME_LOOKUP(Grass)]    = "Grass",
	[ELEMENT_NAME_LOOKUP(Ice)]      = "Ice",
	[ELEMENT_NAME_LOOKUP(Fighting)] = "Fighting",
	[ELEMENT_NAME_LOOKUP(Poison)]   = "Poison",
	[ELEMENT_NAME_LOOKUP(Ground)]   = "Ground",
	[ELEMENT_NAME_LOOKUP(Flying)]   = "Flying",
	[ELEMENT_NAME_LOOKUP(Psychic)]  = "Psychic",
	[ELEMENT_NAME_LOOKUP(Bug)]      = "Bug",
	[ELEMENT_NAME_LOOKUP(Rock)]     = "Rock",
	[ELEMENT_NAME_LOOKUP(Ghost)]    = "Ghost",
	[ELEMENT_NAME_LOOKUP(Dragon)]   = "Dragon",
	[ELEMENT_NAME_LOOKUP(Dark)]     = "Dark",
	[ELEMENT_NAME_LOOKUP(Steel)]    = "Steel",
	[ELEMENT_NAME_LOOKUP(Fairy)]    = "Fairy",
}};

const std::array<std::array<float, ELEMENT_COUNT>, ELEMENT_COUNT> TypeAdvantageLookupTable = {{
	[ELEMENT_NAME_LOOKUP(Normal)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 0.5f,  // Pokemon[Actual] = 1.0 [Changed]
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 0.5f,  // Pokemon[Actual] = 0.5
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 0.0f,  // Pokemon[Actual] = 0.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 0.5f,  // Pokemon[Actual] = 0.5
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Fire)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 0.5f,  // Pokemon[Actual] = 0.5
		[ELEMENT_NAME_LOOKUP(Water)]    = 0.5f,  // Pokemon[Actual] = 0.5
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Water)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Electric)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Grass)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Ice)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Fighting)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Poison)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Ground)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Flying)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Psychic)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Bug)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Rock)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Ghost)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Dragon)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Dark)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Steel)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME_LOOKUP(Fairy)] = {{
		[ELEMENT_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
}};
