#pragma once
#include "Piece.h"

class Pawn : public Piece
{
	bool isMovedOnce;
	bool isReadyToSwap;
	
public:
	Pawn(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition);
	
	void calculatePossiblePositions();
	bool isPawnMovedOnce();
	void setMovedOnce(bool _isMovedOnce);
	bool isPawnReadyToSwap();
};

