#include "StartSquare.h"
#include "Player.h"

void StartSquare::onStay(Player& player)
{}

void StartSquare::onPass(Player& player)
{
	player.modifyWealth(value);
}
