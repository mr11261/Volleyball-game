#include "Configuration.hpp"

static_assert(Configuration::PLAYER_WIDTH <= Configuration::PLAYER_HEIGHT,
              "Player's width cannot be larger than height.");
