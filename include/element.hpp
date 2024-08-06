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

#define ELEMENT_NAME(type) static_cast<uint8_t>(ElementType::type)
const std::array<const std::string, ELEMENT_COUNT> TypeNameLookupTable = {{
	[ELEMENT_NAME(Normal)]   = "Normal",
	[ELEMENT_NAME(Fire)]     = "Fire",
	[ELEMENT_NAME(Water)]    = "Water",
	[ELEMENT_NAME(Electric)] = "Electric",
	[ELEMENT_NAME(Grass)]    = "Grass",
	[ELEMENT_NAME(Ice)]      = "Ice",
	[ELEMENT_NAME(Fighting)] = "Fighting",
	[ELEMENT_NAME(Poison)]   = "Poison",
	[ELEMENT_NAME(Ground)]   = "Ground",
	[ELEMENT_NAME(Flying)]   = "Flying",
	[ELEMENT_NAME(Psychic)]  = "Psychic",
	[ELEMENT_NAME(Bug)]      = "Bug",
	[ELEMENT_NAME(Rock)]     = "Rock",
	[ELEMENT_NAME(Ghost)]    = "Ghost",
	[ELEMENT_NAME(Dragon)]   = "Dragon",
	[ELEMENT_NAME(Dark)]     = "Dark",
	[ELEMENT_NAME(Steel)]    = "Steel",
	[ELEMENT_NAME(Fairy)]    = "Fairy",
}};

const std::array<std::array<float, ELEMENT_COUNT>, ELEMENT_COUNT> TypeAdvantageLookupTable = {{
	[ELEMENT_NAME(Normal)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 0.5f,  // Pokemon[Actual] = 1.0 [Changed]
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 0.5f,  // Pokemon[Actual] = 0.5
		[ELEMENT_NAME(Ghost)]    = 0.0f,  // Pokemon[Actual] = 0.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 0.5f,  // Pokemon[Actual] = 0.5
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Fire)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 0.5f,  // Pokemon[Actual] = 0.5
		[ELEMENT_NAME(Water)]    = 0.5f,  // Pokemon[Actual] = 0.5
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Water)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Electric)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Grass)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Ice)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Fighting)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Poison)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Ground)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Flying)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Psychic)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Bug)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Rock)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Ghost)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Dragon)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Dark)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Steel)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[ELEMENT_NAME(Fairy)] = {{
		[ELEMENT_NAME(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[ELEMENT_NAME(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
}};
