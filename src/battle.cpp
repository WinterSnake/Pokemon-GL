/*
	Pokemon
	- Battle Instance

	Written By: Ryan Smith
*/
#include "battle.hpp"

BattleInstance::BattleInstance() {}

void BattleInstance::AddPokemon(Pokemon& pokemon, BattlePosition position)
{
	switch(position)
	{
		case BattlePosition::User:  UserPokemon.push_back(pokemon); break;
		case BattlePosition::Ally:  AllyPokemon.push_back(pokemon); break;
		case BattlePosition::Enemy: EnemyPokemon.push_back(pokemon); break;
	}
}

void BattleInstance::AddMove(MoveBattle& move)
{
	(void)move;
}
