#pragma once
#include "Piece.h"

class Bishop : public Piece
{

public:
	Bishop(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition);
	void calculatePossiblePositions();
};
