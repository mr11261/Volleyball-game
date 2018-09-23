#include "Configuration.hpp"

static_assert(Configuration::PLAYER_WIDTH <= Configuration::PLAYER_HEIGHT,
	      "Player's width cannont be larger than player's height");
