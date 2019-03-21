#pragma once
#include "StartSquare.h"
#include "BonusSquare.h"
#include "PenaltySquare.h"
#include "DepositSquare.h"
#include "FieldType.h"
#include <vector>
#include <array>
#include <memory>



class Board
{

public:
	Board() :

		fields{ std::make_unique<StartSquare>(1000),
				std::make_unique<BonusSquare>(300),
				std::make_unique<PenaltySquare>(300),
				std::make_unique<DepositSquare>(300),
				std::make_unique<BonusSquare>(300),
				std::make_unique<PenaltySquare>(300),
				std::make_unique<DepositSquare>(300),
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
				std::make_unique<PenaltySquare>(300),
				std::make_unique<BonusSquare>(300),
				std::make_unique<PenaltySquare>(300),
				std::make_unique<BonusSquare>(300),
				std::make_unique<PenaltySquare>(300),
				std::make_unique<BonusSquare>(300),
				std::make_unique<PenaltySquare>(300),
				std::make_unique<BonusSquare>(300),
				std::make_unique<PenaltySquare>(300),
				std::make_unique<BonusSquare>(300) } {}
	
	~Board() = default;

	std::unique_ptr<ISquare>& getStart()
	{
		return fields.front();
	}

	auto& operator[](int index)
	{
		return fields[index];
	}

private:
	//std::vector<std::unique_ptr<ISquare>> fields;
	static constexpr int BOARD_SIZE = 40;
	std::array <std::unique_ptr<ISquare>, BOARD_SIZE> fields;
};

