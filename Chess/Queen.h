#pragma once
#include "Piece.h"

class Queen : public Piece
{

public:
	Queen(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition);
	void calculatePossiblePositions();
};
