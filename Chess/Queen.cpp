#include "stdafx.h"
#include "Queen.h"
#include "Board.h"

void Queen::calculatePossiblePositions()
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

	bool flagUpRight = true;
	bool flagUpLeft = true;
	bool flagDownRight = true;
	bool flagDownLeft = true;

	for (int i = 1; i < 8; i++)
	{
		//UP LEFT 
		if (x-i >= 0 && y-i >= 0 && flagUpLeft)
		{
			if(this->getPointerToBoard()->getPieceOnBoard(x-i,y-i) == nullptr && flagUpLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y-i),(BOARD_SIZE-x+i)));
			}
			else if(this->getPointerToBoard()->getPieceOnBoard(x-i,y-i)->getColour() != this->getColour() && flagUpLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y-i),(BOARD_SIZE-x+i)));
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
		//UP RIGHT
		if (x-i >= 0 && y+i <= 7 && flagUpRight)
		{
			if (this->getPointerToBoard()->getPieceOnBoard(x-i,y+i) == nullptr && flagUpRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y+i),(BOARD_SIZE-x+i)));
			}
			else if (this->getPointerToBoard()->getPieceOnBoard(x-i,y+i)->getColour() != this->getColour() && flagUpRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y+i),(BOARD_SIZE-x+i)));
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
		//DOWN LEFT
		if (x+i <= 7 && y-i >= 0 && flagDownLeft)
		{
			if (this->getPointerToBoard()->getPieceOnBoard(x+i,y-i) == nullptr && flagDownLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y-i),(BOARD_SIZE-x-i)));
			}
			else if (this->getPointerToBoard()->getPieceOnBoard(x+i,y-i)->getColour() != this->getColour() && flagDownLeft)
			{
				this->addPossiblePosition(Position((xCoordinate)(y-i),(BOARD_SIZE-x-i)));
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
		//DOWN RIGHT
		if (x+i <= 7 && y+i <= 7 && flagDownRight)
		{
			if (this->getPointerToBoard()->getPieceOnBoard(x+i,y+i) == nullptr && flagDownRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y+i),(BOARD_SIZE-x-i)));
			}
			else if (this->getPointerToBoard()->getPieceOnBoard(x+i,y+i)->getColour() != this->getColour() && flagDownRight)
			{
				this->addPossiblePosition(Position((xCoordinate)(y+i),(BOARD_SIZE-x-i)));
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



Queen::Queen(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition)
	: Piece(_pieceColour, _representation, _pointerToBoard, _currentPosition)
{

}
