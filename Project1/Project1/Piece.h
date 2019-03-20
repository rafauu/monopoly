#pragma once
#include <memory>
#include <vector>
#include "ISquare.h"
class Piece
{
public:
	//Piece() {};
	Piece(std::unique_ptr<ISquare>& startingSquare) : currentSquare(startingSquare) {}
	~Piece() = default;
	std::unique_ptr<ISquare>& moveToNextSquare()
	{
		currentSquare = std::make_unique< ISquare> (currentSquare.get()+1);
		return currentSquare;
	}
private:
	ISquare& currentSquare;
};

