#pragma once
#include "ISquare.h"

class Player;

class StartSquare :
	public ISquare
{
public:
	StartSquare(int value) : value(value) {}
	void onStay(Player& player);
	void onPass(Player& player);
	~StartSquare() = default;

private:
	int value;
};