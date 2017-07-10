#pragma once
#include "Piece.h"

class Knight : public Piece
{

public:
	Knight(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition);
	void calculatePossiblePositions();
};