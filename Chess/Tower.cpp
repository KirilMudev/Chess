#include "stdafx.h"
#include "Tower.h"
#include "Board.h"

void Tower::calculatePossiblePositions()
{
	int x = BOARD_SIZE - this->getPosition().getY();
	int y = this->getPosition().getX();

	bool flagUp = true;
	bool flagDown = true;
	bool flagLeft = true;
	bool flagRight = true;

	for (int i = 1; i < 8; i++)
	{
		if (x-i >= 0 && flagUp)
		{
			if(this->getPointerToBoard()->getPieceOnBoard(x-i,y) == nullptr && flagUp)
			{
				this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x+i)));
			}
			else if(this->getPointerToBoard()->getPieceOnBoard(x-i,y)->getColour() != this->getColour() && flagUp)
			{
				this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x+i)));
				flagUp = false;
			}
			else
			{
				flagUp = false;
			}
		}
		else
		{
			flagUp = false;
		}

		if (x+i <= 7 && flagDown)
		{
			if (this->getPointerToBoard()->getPieceOnBoard(x+i,y) == nullptr && flagDown)
			{
				this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x-i)));
			}
			else if (this->getPointerToBoard()->getPieceOnBoard(x+i,y)->getColour() != this->getColour() && flagDown)
			{
				this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x-i)));
				flagDown = false;
			}
			else
			{
				flagDown = false;
			}
		}
		else
		{
			flagDown = false;
		}

		if (y+i <= 7 && flagRight)
		{
			if (this->getPointerToBoard()->getPieceOnBoard(x,y+i) == nullptr && flagRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y+i),(BOARD_SIZE-x)));
			}
			else if (this->getPointerToBoard()->getPieceOnBoard(x,y+i)->getColour() != this->getColour() && flagRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y+i),(BOARD_SIZE-x)));
				flagRight = false;
			}
			else
			{
				flagRight = false;
			}
		}
		else
		{
			flagRight = false;
		}

		if (y-i >= 0 && flagLeft)
		{
			if (this->getPointerToBoard()->getPieceOnBoard(x,y-i) == nullptr && flagLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y-i),(BOARD_SIZE-x)));
			}
			else if (this->getPointerToBoard()->getPieceOnBoard(x,y-i)->getColour() != this->getColour() && flagLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y-i),(BOARD_SIZE-x)));
				flagLeft = false;
			}
			else
			{
				flagLeft = false;
			}
		}
		else
		{
			flagLeft = false;
		}

		if(!flagUp && !flagDown && !flagLeft && !flagRight)
		{
			break;
		}
	}
} 

Tower::Tower(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition) 
	: Piece(_pieceColour, _representation, _pointerToBoard, _currentPosition)
{

}
