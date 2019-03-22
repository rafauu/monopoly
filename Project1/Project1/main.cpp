#include <iostream>
#include "MonopolyGame.h"

int main()
{
	std::vector<std::unique_ptr<ISquare>> temp;
	temp.emplace_back(std::make_unique<BonusSquare>(300));
	temp.emplace_back(std::make_unique<BonusSquare>(300));
	temp.emplace_back(std::make_unique<EstateSquare>(300, 100));


	MonopolyGame gaem{ 
		{ Die({1,2,3,4,5,6}), Die({1,2,3,4,5,6}) } ,
		std::array <std::unique_ptr<ISquare>, BOARD_SIZE>{ std::make_unique<StartSquare>(1000),
												           std::make_unique<BlackHole>(std::make_unique<BonusSquare>(300)),
												           std::make_unique<EstateSquare>(400, 100),
												           std::make_unique<DepositSquare>(300),
														   std::make_unique<RandomSquare>(std::move(temp)),
														   std::make_unique<PenaltySquare>(3000),
												           std::make_unique<EstateSquare>(400, 100),
												           std::make_unique<BonusSquare>(300),
												           std::make_unique<PenaltySquare>(300),
												           std::make_unique<BonusSquare>(300),
												           std::make_unique<PenaltySquare>(300),
												           std::make_unique<EstateSquare>(300, 200),
												           std::make_unique<PenaltySquare>(300),
												           std::make_unique<BonusSquare>(300),
												           std::make_unique<PenaltySquare>(300),
												           std::make_unique<EstateSquare>(400, 100),
												           std::make_unique<PenaltySquare>(300),
												           std::make_unique<BonusSquare>(300),
												           std::make_unique<PenaltySquare>(300),
												           std::make_unique<BonusSquare>(300),
												           std::make_unique<PenaltySquare>(300),
												           std::make_unique<BonusSquare>(300),
												           std::make_unique<PenaltySquare>(300),
												           std::make_unique<BonusSquare>(300),
												           std::make_unique<PenaltySquare>(300),
												           std::make_unique<BonusSquare>(300),
												           std::make_unique<PenaltySquare>(300),
	                                                       std::make_unique<BonusSquare>(300),
	                                                       std::make_unique<EstateSquare>(400, 100),
	                                                       std::make_unique<BonusSquare>(300),
	                                                       std::make_unique<PenaltySquare>(300),
	                                                       std::make_unique<BonusSquare>(300),
	                                                       std::make_unique<PenaltySquare>(300),
	                                                       std::make_unique<BonusSquare>(300),
	                                                       std::make_unique<PenaltySquare>(300),
	                                                       std::make_unique<BonusSquare>(300),
	                                                       std::make_unique<PenaltySquare>(300),
	                                                       std::make_unique<BonusSquare>(300),
	                                                       std::make_unique<EstateSquare>(400, 100),
	                                                       std::make_unique<BonusSquare>(300) },
	{ std::make_shared<GreedyAiPlayer>("Andrzej", 1000),
      std::make_shared<RandomAiPlayer>("Duda", 1000) ,
	  std::make_shared<HumanPlayer>("Bezimienny", 1000) } };


	gaem.play();
	std::cin.get();
	return 0;
}
