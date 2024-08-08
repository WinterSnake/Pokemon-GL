/*
	Pokemon
	- Pokemon

	Written By: Ryan Smith
*/
#include "pokemon.hpp"

MoveBattle::MoveBattle(const MoveInfo* info):
	Info(info)
{
	if (info == nullptr)
		return;
	PP = info->PP;
}
