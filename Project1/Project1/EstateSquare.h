#pragma once
#include "ISquare.h"
#include <memory>

class Player;

class EstateSquare :
	public ISquare
{
public:
	EstateSquare(int value, int rent) : value(value), rent(rent) {}
	void onStay(Player& player);
	void onPass(Player& player);
	~EstateSquare() = default;
private:
	void drainRent(Player& player);
	void offerPurchase(Player& player);
	bool estateIsntOwned();
	bool playerIsNotOwner(Player& player);
	int value;
	int rent;
	std::shared_ptr<Player> owner = nullptr;
};