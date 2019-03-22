#include "BlackHole.h"
#include "Player.h"
#include <random>

void BlackHole::onStay(Player& player)
{
	shouldBeExecutedOnStay ^= true;
	if (shouldBeExecutedOnStay)
	{
		square->onStay(player);
	}
}

void BlackHole::onPass(Player& player)
{
	shouldBeExecutedOnPass ^= true;
	if (shouldBeExecutedOnPass)
	{
		square->onStay(player);
	}
}
