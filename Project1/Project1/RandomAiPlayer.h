#pragma once
#include <random>
#include "Player.h"

class RandomAiPlayer : public Player
{
public:
	RandomAiPlayer(std::string name, int money, int startingSquare = 0) :
		Player(name, money, startingSquare) {};
	bool promptBuyout(int price, int rent)  override
	{
		std::mt19937 rng(rd());
		bool rand_bool = std::uniform_int_distribution<>{ 0, 1 }(rng);

		std::cout << "AI: Landed on an estate square (Price: " << price << " / Rent: " << rent << "), random decision: " << rand_bool << std::endl;
		return true;
	};
private:
	std::random_device rd;
};