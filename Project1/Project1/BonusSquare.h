#pragma once
#include "ISquare.h"

class Player;

class BonusSquare :
	public ISquare
{
public:
	BonusSquare(int value) : value(value) {}
	void onStay(Player& player);
	void onPass(Player& player);
	~BonusSquare() = default;
private:
	int value;
};