#include "Player.h"

void Player::modifyWealth(int value)
{
	money += value;
}

std::unique_ptr<ISquare>& Player::movePiece()
{
	return piece.moveToNextSquare();
}

bool Player::isBankrupt() const
{
	return money < 0;
}
