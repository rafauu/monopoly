#pragma once
#include "ISquare.h"
#include <memory>
class Player;

class BlackHole : public ISquare
{
public:
	BlackHole(std::unique_ptr<ISquare>&& square) : square(std::move(square)) {}
	void onStay(Player& player);
	void onPass(Player& player);
private:
	std::unique_ptr<ISquare> square;
	bool shouldBeExecutedOnPass;
	bool shouldBeExecutedOnStay;
};