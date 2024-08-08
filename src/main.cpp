/*
	Pokemon

	Written By: Ryan Smith
*/
#include <iostream>
#include <string>
#include "pokemon.hpp"
#include "species.hpp"
#include "moves.hpp"

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
	return 0;
}
