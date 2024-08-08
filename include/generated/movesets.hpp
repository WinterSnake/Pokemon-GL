#pragma once
#include <array>
#include "pokemon.hpp"
#include "moves.hpp"

const std::array<const MoveLearn, 2> CharmanderMoveset = {{
	{ MOVE_SCRATCH, 1, },
	{ MOVE_GROWL, 1, },
}};

const std::array<const MoveLearn, 2> BulbasaurMoveset = {{
	{ MOVE_TACKLE, 1, },
	{ MOVE_GROWL, 1, },
}};

const std::array<const MoveLearn, 2> SquirtleMoveset = {{
	{ MOVE_TACKLE, 1, },
	{ MOVE_TAIL_WHIP, 1, },
}};
