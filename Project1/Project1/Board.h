#pragma once
#include "StartSquare.h"
#include "BonusSquare.h"
#include "PenaltySquare.h"
#include "DepositSquare.h"
#include "EstateSquare.h"
#include "RandomSquare.h"
#include "BlackHole.h"
#include "FieldType.h"
#include <vector>
#include <array>
#include <memory>



class Board
{

public:
	Board(std::array <std::unique_ptr<ISquare>, BOARD_SIZE> fields) : fields{ std::move(fields) } {}
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
	std::array <std::unique_ptr<ISquare>, BOARD_SIZE> fields;
};

