/*
	Pokemon

	Written By: Ryan Smith
*/
#include <iostream>
#include <string>
#include "pokemon.hpp"
#include "species.hpp"
#include "moves.hpp"
#include "battle.hpp"

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	Pokemon charmander = {
		.Info = SPECIES_CHARMANDER,
		.Moves = {{
			MoveBattle(MOVE_SCRATCH),
			MoveBattle(MOVE_EMBER),
			MoveBattle(MOVE_GROWL),
			NULL,
		}}
	};
	Pokemon bulbasaur = {
		.Info = SPECIES_BULBASAUR,
		.Moves = {{
			MoveBattle(MOVE_TACKLE),
			MoveBattle(MOVE_ABSORB),
			MoveBattle(MOVE_TAIL_WHIP),
			NULL,
		}}
	};
	// Battle
	BattleInstance battle;
	battle.AddPokemon(charmander, BattlePosition::User);
	battle.AddPokemon(bulbasaur, BattlePosition::Enemy);
	// Write move output
	for (size_t i = 0; i < charmander.Moves.size(); ++i)
	{
		if (charmander.Moves[i].Info == nullptr)
			continue;
		if (i != 0 && i < charmander.Moves.size())
			std::cout << ';';
		std::cout << '[' << i + 1 << ']' << charmander.Moves[i].Info->Name;
	}
	std::cout << '\n';
	while (true)
	{
		char input;
		std::cin >> input;
		if (input < '0' || input > '4') break;
		uint8_t move_index = input - '0' - 1;
		const MoveInfo* moveInfo = charmander.Moves[move_index].Info;
		if (moveInfo == nullptr)
		{
			std::cout << "Invalid move..\n";
			continue;
		}
		std::cout << charmander.Info->Name << " used " << moveInfo->Name << '\n';
	}
	return 0;
}
