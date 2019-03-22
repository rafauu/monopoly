#include "RandomSquare.h"
#include "Player.h"
#include <random>

void RandomSquare::onStay(Player& player)
{
	std::mt19937 rng(rd());
	unsigned squareIndex = std::uniform_int_distribution<>{ 0, 2 }(rng);
	squares[squareIndex]->onStay(player);
}

void RandomSquare::onPass(Player& player)
{
}
