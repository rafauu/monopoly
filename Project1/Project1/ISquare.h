#pragma once
class Player;

class ISquare
{
public:
	virtual ~ISquare() = default;

	virtual void onStay(Player& player) = 0;
	virtual void onPass(Player& player) = 0;
};