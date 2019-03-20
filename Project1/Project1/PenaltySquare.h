#pragma once
#include "ISquare.h"

class Player;

class PenaltySquare :
	public ISquare
{
public:
	PenaltySquare(int value) : value(value) {}
	void onStay(Player& player);
	void onPass(Player& player);
	~PenaltySquare() = default;

private:
	int value;
};