/*
	Pokemon
	- Pokemon

	Written By: Ryan Smith
*/
#include "pokemon.hpp"

Pokemon Pokemon::FromInfo(const PokemonInfo* info, uint8_t level)
{
	(void)level;
	// Create move array
	std::array<MoveBattle, BATTLE_MOVES_COUNT> moves;
	for (size_t i = 0; i < info->MovesetSize; ++i)
	{
		// TODO: check level moveset
		const MoveInfo* move = info->Moveset[i].Info;
		moves[i] = { .Info = move, .PP = move->PP }; 
	}
	// Return created pokemon
	return {
		.Info = info,
		.Moves = moves,
	};
}
