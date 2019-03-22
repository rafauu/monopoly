#include "EstateSquare.h"
#include "Player.h"

void EstateSquare::onStay(Player& player)
{
	if (owner == nullptr )
	{
		if(player.promptBuyout(value, rent))
		{
			owner = std::make_shared<Player>(player);
			player.modifyWealth(-value);
		}
		return;
	}
	if (owner.get() != &player)
	{
		owner->modifyWealth(rent);
		player.modifyWealth(-rent);
	}
}

void EstateSquare::onPass(Player& player)
{
}
