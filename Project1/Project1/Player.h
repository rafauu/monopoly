#pragma once
#include <iostream>
#include <string>
#include "Piece.h"
class Square;

class Player
{
public:
	Player(std::string name, int money, std::unique_ptr<ISquare>& startingSquare) :
		name(name), money(money), piece(startingSquare) {};
	~Player() = default;

	void modifyWealth(int value);

	std::unique_ptr<ISquare>& movePiece();

	bool isBankrupt() const;

	friend std::ostream& operator<<(std::ostream& os, const Player& player)
	{
		return std::cout << "Player name : " << player.name << " wealth: " << player.money << std::endl;
	}
private:
	std::string name;
	int money;
	Piece piece;
};



