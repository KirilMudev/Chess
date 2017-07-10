#pragma once
#include "Piece.h"

class King : public Piece
{
	bool castlingStatus;

public:
	King();
	King(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition);
	//void castle(King _king, Tower _tower){}; //based on castlingStatus will perform the action (still not finished)
	void calculatePossiblePositions(); //not fully functional, needs all positions to be sandboxed and added after that
	
};
