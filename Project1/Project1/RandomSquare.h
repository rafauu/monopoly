#pragma once
#include "ISquare.h"
#include <vector>
#include <memory>
#include <random>

class Player;

class RandomSquare :
	public ISquare
{
public:
	RandomSquare(std::vector<std::unique_ptr<ISquare>>&& squares) : squares{ std::move(squares) } {}
	void onStay(Player& player);
	void onPass(Player& player);
	~RandomSquare() = default;

private:
	std::vector<std::unique_ptr<ISquare>> squares;
	std::random_device rd;
};