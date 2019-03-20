#include "DepositSquare.h"
#include "Player.h"

void DepositSquare::onStay(Player& player)
{
	player.modifyWealth(drain);
	value = 0;
}

void DepositSquare::onPass(Player& player)
{
	player.modifyWealth(-drain);
	value += drain;

}
