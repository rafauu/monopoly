#pragma once
#include <array>
#include <vector>
#include <utility>
#include "Die.h"
#include "Board.h"
#include "Player.h"

class MonopolyGame
{
public:
	MonopolyGame() :
		dice{Die({1,2,3,4,5,6}), Die({1,2,3,4,5,6}) },
		board{},
		players{ Player{"Andrzej", 500}, Player{"Duda", 500} }
	{}
	~MonopolyGame() = default;

	void play()
	{
		std::random_device rnd_device;
		while (not lastManStanding())
		{
			for (auto& player : players)
			{
				auto diceRoll = rollEveryDice(rnd_device);
				std::cout << " Player " << player << " rolled " << diceRoll << std::endl;
				for (int step=0; step < diceRoll - 1; ++step)
				{
					auto nextSquare = player.movePiece();
					//(*nextSquare).onPass(player);
					board[nextSquare]->onPass(player);
				}
				
				auto nextSquare = player.movePiece();
				std::cout << 40 - nextSquare << std::endl;
				//(*nextSquare).onStay(player);
				board[nextSquare]->onStay(player);
			}
		}
	}

	std::vector<Die> dice;
	Board board;
	std::vector<Player> players;
private:
	int rollEveryDice(std::random_device& rng)
	{
		int roll{ 0 };
		for (auto& die : dice)
		{
			std::cout << "wtf: roll: " << roll << std::endl;
			roll += die.roll(rng);
		}
		return roll;
	}

	bool lastManStanding()
	{
		const int LASTMAN{ 1 };
		return LASTMAN == std::count_if(players.cbegin(),
			                            players.cend(),
			                            [this](const auto& player) { return not player.isBankrupt(); });
		/*int cnt = 0;
		for (auto player : players)
		{
			if (player.isBankrupt())
				++cnt;
		}
		return cnt == 1;*/
	}
};

