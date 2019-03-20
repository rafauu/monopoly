#pragma once
#include "ISquare.h"

class Player;

class DepositSquare :
	public ISquare
{
public:
	DepositSquare(int drain) : drain(drain) {}
	void onStay(Player& player);
	void onPass(Player& player);
	~DepositSquare() = default;

private:
	int drain;
	int value{ 0 };
};