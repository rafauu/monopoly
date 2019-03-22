#include "EstateSquare.h"
#include "Player.h"

void EstateSquare::onStay(Player& player)
{
	if (estateIsntOwned())
	{
		offerPurchase(player);
		return;
	}
	if (playerIsNotOwner(player))
	{
		drainRent(player);
	}
}

void EstateSquare::drainRent(Player& player)
{
	owner->modifyWealth(rent);
	player.modifyWealth(-rent);
}

void EstateSquare::offerPurchase(Player& player)
{
	if (player.promptBuyout(value, rent))
	{
		owner = std::make_shared<Player>(player);
		player.modifyWealth(-value);
	}
}

bool  EstateSquare::estateIsntOwned()
{
	return owner == nullptr;
}

bool  EstateSquare::playerIsNotOwner(Player& player)
{
	return owner.get() != &player;
}

void EstateSquare::onPass(Player& player)
{
}
