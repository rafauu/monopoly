#include "PenaltySquare.h"
#include "Player.h"

void PenaltySquare::onStay(Player& player)
{
	player.modifyWealth(-value);
}

void PenaltySquare::onPass(Player& player)
{
}
