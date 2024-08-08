#pragma once
#include <array>
#include <string>
#include "pokemon.hpp"
#include "movesets.hpp"

constexpr size_t SPECIES_COUNT = 3;
const std::array<const PokemonInfo, SPECIES_COUNT> POKEMON_SPECIES = {{
	{
		.Name = "Charmander",
		.Elements = {{ ElementType::Fire, ElementType::Fire }},
		.Moveset = CharmanderMoveset.data(),
		.MovesetSize = CharmanderMoveset.size(),
	},
	{
		.Name = "Bulbasaur",
		.Elements = {{ ElementType::Grass, ElementType::Poison }},
		.Moveset = BulbasaurMoveset.data(),
		.MovesetSize = BulbasaurMoveset.size(),
	},
	{
		.Name = "Squirtle",
		.Elements = {{ ElementType::Water, ElementType::Water }},
		.Moveset = SquirtleMoveset.data(),
		.MovesetSize = SquirtleMoveset.size(),
	},
}};

const PokemonInfo* SPECIES_CHARMANDER = &POKEMON_SPECIES[0];
const PokemonInfo* SPECIES_BULBASAUR  = &POKEMON_SPECIES[1];
const PokemonInfo* SPECIES_SQUIRTLE   = &POKEMON_SPECIES[2];
