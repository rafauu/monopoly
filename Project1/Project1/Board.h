#pragma once
#include "StartSquare.h"
#include "BonusSquare.h"
#include "PenaltySquare.h"
#include "DepositSquare.h"
#include "FieldType.h"
#include <vector>
#include <memory>



class Board
{

public:
	Board() :

		fields{ std::make_unique<StartSquare>(1000),
				std::make_unique<BonusSquare>(300),
				std::make_unique<PenaltySquare>(300),
				std::make_unique<DepositSquare>(300) } {}
	
	~Board() = default;

	std::unique_ptr<ISquare>& getStart()
	{
		return fields.front();
	}

	std::unique_ptr<ISquare>& getEnd()
	{
		return fields.back();
	}

private:
	std::vector<std::unique_ptr<ISquare>> fields;
};

