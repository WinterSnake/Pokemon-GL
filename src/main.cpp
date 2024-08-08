/*
	Pokemon

	Written By: Ryan Smith
*/
#include <iostream>
#include <string>
#include "pokemon.hpp"
#include "generated/species.hpp"
#include "generated/moves.hpp"
#include "battle.hpp"

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	Pokemon charmander = Pokemon::FromInfo(SPECIES_CHARMANDER, 5);
	Pokemon bulbasaur  = Pokemon::FromInfo(SPECIES_BULBASAUR,  5);
	// Battle
	BattleInstance battle;
	battle.AddPokemon(charmander, BattlePosition::User);
	battle.AddPokemon(bulbasaur, BattlePosition::Enemy);
	while (true)
	{
		// Write move output
		for (size_t i = 0; i < charmander.Moves.size(); ++i)
		{
			auto move = charmander.Moves[i];
			if (move.Info == nullptr)
				continue;
			if (i != 0 && i < charmander.Moves.size())
				std::cout << " ; ";
			std::cout << '[' << i + 1 << ']' << move.Info->Name << '(' << (int)move.PP << ')';
		}
		std::cout << '\n';
		// Get move input
		char input;
		std::cin >> input;
		if (input < '0' || input > '4') break;
		uint8_t move_index = input - '0' - 1;
		auto move = charmander.Moves[move_index];
		// Handle invalid move
		if (move.Info == nullptr)
		{
			std::cout << "Invalid move..\n";
			continue;
		}
		// Handle no pp
		else if (move.PP == 0)
		{
			std::cout << "No pp left..\n";
			continue;
		}
		std::cout << charmander.Info->Name << " used " << move.Info->Name << '\n';
		// Simulate battle
		battle.AddMove(charmander.Moves[move_index]);
	}
	return 0;
}
