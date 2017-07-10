#include "stdafx.h"
#include "King.h"
#include "Board.h"

King::King()
{
	this->castlingStatus = true;
}

void King::calculatePossiblePositions()
{
	//found bug is that the king can approach cells, where he's in check (still not fixed)
	int x = BOARD_SIZE - this->getPosition().getY();
	int y = this->getPosition().getX();

	if (x-1 >= 0 && y-1 >= 0)
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x-1,y-1) == nullptr)
		{
			this->addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x+1))); 
		}
		else if (this->getPointerToBoard()->getPieceOnBoard(x-1,y-1)->getColour() != this->getColour())
		{
			this->addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x+1)));
		}
	}

	if (x+1 <= 7 && y+1 <= 7)
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x+1,y+1) == nullptr)
		{
			this->addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x-1))); 
		}
		else if (this->getPointerToBoard()->getPieceOnBoard(x+1,y+1)->getColour() != this->getColour())
		{
			this->addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x-1)));
		}
	}

	if (x-1 >= 0)
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x-1,y) == nullptr)
		{
			this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x+1))); 
		}
		else if (this->getPointerToBoard()->getPieceOnBoard(x-1,y)->getColour() != this->getColour())
		{
			this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x+1)));
		}
	}

	if (x+1 <= 7)
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x+1,y) == nullptr)
		{
			this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x-1))); 
		}
		else if (this->getPointerToBoard()->getPieceOnBoard(x+1,y)->getColour() != this->getColour())
		{
			this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x-1)));
		}
	}

	if (y+1 <= 7)
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x,y+1) == nullptr)
		{
			this->addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x))); 
		}
		else if (this->getPointerToBoard()->getPieceOnBoard(x,y+1)->getColour() != this->getColour())
		{
			this->addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x)));	
		}
	}

	if (y-1 >= 0)
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x,y-1) == nullptr)
		{
			this->addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x))); 
		}
		else if (this->getPointerToBoard()->getPieceOnBoard(x,y-1)->getColour() != this->getColour())
		{
			this->addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x)));
		}
	}
	
	if (x+1 <= 7 && y-1 >= 0)
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x+1,y-1) == nullptr)
		{
			this->addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x-1))); 
		}
		else if (this->getPointerToBoard()->getPieceOnBoard(x+1,y-1)->getColour() != this->getColour())
		{
			this->addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x-1)));
		}
	}

	if (x-1 >= 0 && y+1 <= 7)
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x-1,y+1) == nullptr)
		{
			this->addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x+1))); 
		}
		else if (this->getPointerToBoard()->getPieceOnBoard(x-1,y+1)->getColour() != this->getColour())
		{
			this->addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x+1)));
		}
	}

	//after that we run checkAvailabilty, if it returns (normal) -> we can proceed, else - we repeat
} 

King::King(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition) 
	: Piece( _pieceColour, _representation,  _pointerToBoard, _currentPosition)
{
	this->castlingStatus = true;
}