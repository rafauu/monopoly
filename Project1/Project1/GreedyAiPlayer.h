#pragma once

#include "Player.h"

class GreedyAiPlayer : public Player
{
public:
	GreedyAiPlayer(std::string name, int money, int startingSquare = 0) :
		Player(name, money, startingSquare) {};
	bool promptBuyout(int price, int rent)  override
	{
		std::cout << "AI: Landed on an estate square (Price: " << price << " / Rent: " << rent << "), automatically buying if possible)" << std::endl;
		return true;
	};
};