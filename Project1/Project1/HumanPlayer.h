#pragma once

#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(std::string name, int money, int startingSquare = 0) :
		Player(name, money, startingSquare) {};
	bool promptBuyout(int price, int rent)  override 
	{
		std::string reply;
		std::cout << "Prompt: Do you want to buy an estate? (Price: " << price << " / Rent: " << rent << "), type y to buy, any other key to cancel)" << std::endl;
		std::getline(std::cin, reply);
		if (reply == "y")
		{
			return true;
		}
		return false;
	};
};