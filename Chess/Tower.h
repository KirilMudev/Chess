#pragma once
#include "Piece.h"

class Tower : public Piece
{
	bool castlingStatus;

public:
	Tower(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition);
	void calculatePossiblePositions(); //castling not calculated
};