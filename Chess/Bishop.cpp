#include "stdafx.h"
#include "Bishop.h"
#include "Board.h"

void Bishop::calculatePossiblePositions()
{
	int x = BOARD_SIZE - this->getPosition().getY();
	int y = this->getPosition().getX();

	bool flagUpRight = true;
	bool flagUpLeft = true;
	bool flagDownRight = true;
	bool flagDownLeft = true;

	for (int i = 1; i < BOARD_SIZE; i++)
	{
		//UP LEFT 
		if (x-i >= 0 && y-i >= 0 && flagUpLeft)
		{
			if(this->getPointerToBoard()->getPieceOnBoard(x - i, y - i) == nullptr && flagUpLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y - i),(BOARD_SIZE - x + i)));
			}
			else if(this->getPointerToBoard()->getPieceOnBoard(x - i, y - i)->getColour() != this->getColour() && flagUpLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y - i),(BOARD_SIZE - x + i)));
				flagUpLeft = false;
			}
			else
			{
				flagUpLeft = false;
			}
		}
		else
		{
			flagUpLeft = false;
		}
		//UPRIGHT
		if (x-i >= 0 && y+i <= 7 && flagUpRight)
		{
			if (this->getPointerToBoard()->getPieceOnBoard(x - i, y + i) == nullptr && flagUpRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y + i),(BOARD_SIZE - x + i)));
			}
			else if (this->getPointerToBoard()->getPieceOnBoard(x - i, y + i)->getColour() != this->getColour() && flagUpRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y + i),(BOARD_SIZE - x + i)));
				flagUpRight = false;
			}
			else
			{
				flagUpRight = false;
		
			}
		}
		else
		{
			flagUpRight = false;
		
		}
		//DOWNLEFT
		if (x+i <= 7 && y-i >= 0 && flagDownLeft)
		{
			if (this->getPointerToBoard()->getPieceOnBoard(x + i, y - i) == nullptr && flagDownLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y - i), (BOARD_SIZE - x - i)));
			}
			else if (this->getPointerToBoard()->getPieceOnBoard(x + i, y - i)->getColour() != this->getColour() && flagDownLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y - i),(BOARD_SIZE - x - i)));
				flagDownLeft = false;
			}	
			else
			{
				flagDownLeft = false;
			}
		}
		else
		{
			flagDownLeft = false;
		}
		//DOWNRIGHT
		if (x+i <= 7 && y+i <= 7 && flagDownRight)
		{
			if (this->getPointerToBoard()->getPieceOnBoard(x + i, y + i) == nullptr && flagDownRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y + i),(BOARD_SIZE - x - i)));
			}
			else if (this->getPointerToBoard()->getPieceOnBoard(x + i, y + i)->getColour() != this->getColour() && flagDownRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y + i),(BOARD_SIZE - x - i)));
				flagDownRight = false;
			}
			else
			{
				flagDownRight = false;
			}		
		}
		else
		{
			flagDownRight = false;
		}

		if(!flagUpLeft && !flagUpRight && !flagDownLeft && !flagDownRight)
		{
			break;
		}
	}
}

Bishop::Bishop(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition) 
	: Piece(_pieceColour, _representation, _pointerToBoard, _currentPosition){}

