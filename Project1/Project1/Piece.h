#pragma once
#include <memory>
#include <vector>
#include "ISquare.h"
#include <iostream>
class Piece
{
public:
	//Piece() {};
	Piece(int startingSquareIndex) : currentSquareIndex(startingSquareIndex) {}
	~Piece() = default;
	int moveToNextSquare()
	{
		std::cout << "wtf is goin on here? : " << currentSquareIndex << std::endl;
		currentSquareIndex += 1;
		return currentSquareIndex;
	}
private:
	int currentSquareIndex;
};

