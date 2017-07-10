#include "stdafx.h"
#include "Knight.h"
#include "Board.h"

void Knight::calculatePossiblePositions()
{
	int x = BOARD_SIZE - this->getPosition().getY(); 
	int y = this->getPosition().getX();     

	if ((x-2 >= 0) && (y-1 >= 0))
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x-2,y-1) == nullptr || 
			this->getPointerToBoard()->getPieceOnBoard(x-2,y-1)->getColour() != this->getColour())
		{
			addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x+2)));
		}		
	}
	
	if ((x-1 >= 0) && (y-2 >= 0))
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x-1,y-2) == nullptr || 
			this->getPointerToBoard()->getPieceOnBoard(x-1,y-2)->getColour() != this->getColour())
		{
			addPossiblePosition(Position((xCoordinate)(y-2),(BOARD_SIZE-x+1)));
		}
	}

	if ((x-2 >= 0) && (y+1 <= 7))
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x-2,y+1) == nullptr || 
			this->getPointerToBoard()->getPieceOnBoard(x-2,y+1)->getColour() != this->getColour())
		{
			addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x+2)));
		}
	}

	if ((x-1 >= 0) && (y+2 <= 7))
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x-1,y+2) == nullptr || 
			this->getPointerToBoard()->getPieceOnBoard(x-1,y+2)->getColour() != this->getColour())
		{
			addPossiblePosition(Position((xCoordinate)(y+2),(BOARD_SIZE-x+1)));
		}
	}

	

	//mirror to first two
	if ((x+2 <= 7) && (y-1 >= 0))
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x+2,y-1) == nullptr || 
			this->getPointerToBoard()->getPieceOnBoard(x+2,y-1)->getColour() != this->getColour())
		{
			addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x-2)));
		}
	}

	if ((x+1 <= 7) && (y-2 >= 0))
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x+1,y-2) == nullptr || 
			this->getPointerToBoard()->getPieceOnBoard(x+1,y-2)->getColour() != this->getColour())
		{
			addPossiblePosition(Position((xCoordinate)(y-2),(BOARD_SIZE-x-1)));
		}
	}

	//mirror to second two
	if ((x+2 <= 7) && (y+1 <= 7))
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x+2,y+1) == nullptr || 
			this->getPointerToBoard()->getPieceOnBoard(x+2,y+1)->getColour() != this->getColour())
		{
			addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x-2)));
		}
	}
	
	if ((x+1 <= 7) && (y+2 <= 7))
	{
		if (this->getPointerToBoard()->getPieceOnBoard(x+1,y+2) == nullptr || 
			this->getPointerToBoard()->getPieceOnBoard(x+1,y+2)->getColour() != this->getColour())
		{
			addPossiblePosition(Position((xCoordinate)(y+2),(BOARD_SIZE-x-1)));
		}
	}

} 

Knight::Knight(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition) 
	: Piece(_pieceColour, _representation, _pointerToBoard, _currentPosition)
{

}
