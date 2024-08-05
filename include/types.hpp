/*
	Pokemon
	- Pokemon Type Matching

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

#define POKEMON_TYPE_COUNT 18
enum class PokemonType : uint8_t
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

float calculate_attack_multiplier(PokemonType attack, PokemonType defenseType1, PokemonType defenseType2);

#define TYPE_NAME_LOOKUP(type) static_cast<uint8_t>(PokemonType::type)
const std::array<const std::string, POKEMON_TYPE_COUNT> TypeNameLookupTable = {{
	[TYPE_NAME_LOOKUP(Normal)]   = "Normal",
	[TYPE_NAME_LOOKUP(Fire)]     = "Fire",
	[TYPE_NAME_LOOKUP(Water)]    = "Water",
	[TYPE_NAME_LOOKUP(Electric)] = "Electric",
	[TYPE_NAME_LOOKUP(Grass)]    = "Grass",
	[TYPE_NAME_LOOKUP(Ice)]      = "Ice",
	[TYPE_NAME_LOOKUP(Fighting)] = "Fighting",
	[TYPE_NAME_LOOKUP(Poison)]   = "Poison",
	[TYPE_NAME_LOOKUP(Ground)]   = "Ground",
	[TYPE_NAME_LOOKUP(Flying)]   = "Flying",
	[TYPE_NAME_LOOKUP(Psychic)]  = "Psychic",
	[TYPE_NAME_LOOKUP(Bug)]      = "Bug",
	[TYPE_NAME_LOOKUP(Rock)]     = "Rock",
	[TYPE_NAME_LOOKUP(Ghost)]    = "Ghost",
	[TYPE_NAME_LOOKUP(Dragon)]   = "Dragon",
	[TYPE_NAME_LOOKUP(Dark)]     = "Dark",
	[TYPE_NAME_LOOKUP(Steel)]    = "Steel",
	[TYPE_NAME_LOOKUP(Fairy)]    = "Fairy",
}};

const std::array<std::array<float, POKEMON_TYPE_COUNT>, POKEMON_TYPE_COUNT> TypeAdvantageLookupTable = {{
	[TYPE_NAME_LOOKUP(Normal)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 0.5f,  // Pokemon[Actual] = 1.0 [Changed]
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 0.5f,  // Pokemon[Actual] = 0.5
		[TYPE_NAME_LOOKUP(Ghost)]    = 0.0f,  // Pokemon[Actual] = 0.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 0.5f,  // Pokemon[Actual] = 0.5
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Fire)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 0.5f,  // Pokemon[Actual] = 0.5
		[TYPE_NAME_LOOKUP(Water)]    = 0.5f,  // Pokemon[Actual] = 0.5
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Water)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Electric)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Grass)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Ice)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Fighting)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Poison)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Ground)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Flying)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Psychic)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Bug)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Rock)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Ghost)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Dragon)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Dark)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Steel)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
	[TYPE_NAME_LOOKUP(Fairy)] = {{
		[TYPE_NAME_LOOKUP(Normal)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fire)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Water)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Electric)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Grass)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ice)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fighting)] = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Poison)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ground)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Flying)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Psychic)]  = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Bug)]      = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Rock)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Ghost)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dragon)]   = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Dark)]     = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Steel)]    = 1.0f,  // Pokemon[Actual] = 1.0
		[TYPE_NAME_LOOKUP(Fairy)]    = 1.0f,  // Pokemon[Actual] = 1.0
	}},
}};
