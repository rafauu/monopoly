#include "BonusSquare.h"
#include "Player.h"

void BonusSquare::onStay(Player& player)
{
	player.modifyWealth(value);
}

void BonusSquare::onPass(Player& player)
{}
