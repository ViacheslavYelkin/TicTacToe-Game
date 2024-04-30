#include "Player.h"

Player::Player(char game_side)
	: game_side_{game_side}
{
}

char Player::getSide() const
{
	return game_side_;
}
