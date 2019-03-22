#pragma once
#include <array>
#include <vector>
#include <utility>
#include "Die.h"
#include "Board.h"
#include "Player.h"
#include "GreedyAiPlayer.h"
#include "RandomAiPlayer.h"
#include "HumanPlayer.h"

class MonopolyGame
{
public:
	MonopolyGame() :
		dice{Die({1,2,3,4,5,6}), Die({1,2,3,4,5,6}) },
		board{},
		players{ std::make_shared<GreedyAiPlayer>("Andrzej", 1000), 
		         std::make_shared<RandomAiPlayer>("Duda", 1000) , 
		         std::make_shared<HumanPlayer>("Bezimienny", 1000) }
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
				std::cout << " Player " << *player << " rolled " << diceRoll << std::endl;
				for (int step=0; step < diceRoll - 1; ++step)
				{
					auto nextSquare = player->movePiece();
					//(*nextSquare).onPass(player);
					board[nextSquare]->onPass(*player);
				}
				
				auto nextSquare = player->movePiece();
				std::cout << 40 - nextSquare << std::endl;
				//(*nextSquare).onStay(player);
				board[nextSquare]->onStay(*player);
			}
		}
		std::cout << "GAME IS OVER, the final standings are... " << std::endl;
		for (auto& player : players)
		{
			std::cout << *player << std::endl;
		}
	}

	std::vector<Die> dice;
	Board board;
	std::vector<std::shared_ptr<Player>> players;
private:
	int rollEveryDice(std::random_device& rng)
	{
		int roll{ 0 };
		for (auto& die : dice)
		{
			
			roll += die.roll(rng);
			std::cout << "wtf: roll: " << roll << std::endl;
		}
		return roll;
	}

	bool lastManStanding()
	{
		const int LASTMAN{ 1 };
		return LASTMAN == std::count_if(players.cbegin(),
			                            players.cend(),
			                            [this](const auto& player) { return not player->isBankrupt(); });
		/*int cnt = 0;
		for (auto player : players)
		{
			if (player.isBankrupt())
				++cnt;
		}
		return cnt == 1;*/
	}
};

