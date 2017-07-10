#include "stdafx.h"
#include "Pawn.h"
#include "Board.h"

void Pawn::calculatePossiblePositions()
{
		int x = BOARD_SIZE - this->getPosition().getY();
		int y = this->getPosition().getX();

		if (this->getColour() == White)
		{
			if (x-1 > 0)
			{
				if (this->getPointerToBoard()->getPieceOnBoard(x-1,y) == nullptr)
				{
					this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x+1))); 
		
					if (!isMovedOnce && this->getPointerToBoard()->getPieceOnBoard(x-2,y) == nullptr)
					{
						this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x+2)));
					}
				}
			}
	
			if (x-1 > 0 && y-1 >= 0 && this->getPointerToBoard()->getPieceOnBoard(x-1,y-1) != nullptr)
			{
				if ((this->getPointerToBoard()->getPieceOnBoard(x-1,y-1)->getColour() != this->getColour()))
				{
					this->addPossiblePosition(Position((xCoordinate)(y-1),BOARD_SIZE-x+1));
				}
			}

			if (x-1 > 0 && y+1 <= 7 && this->getPointerToBoard()->getPieceOnBoard(x-1,y+1) != nullptr)
			{
				if ((this->getPointerToBoard()->getPieceOnBoard(x-1,y+1)->getColour() != this->getColour()))
				{
					this->addPossiblePosition(Position((xCoordinate)(y+1),BOARD_SIZE-x+1));	
				}
			}

			//FINAL STEP FOR WHITE PAWNS
			if (x-1 == 0 && this->getPointerToBoard()->getPieceOnBoard(x-1,y) == nullptr)
			{
				this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x+1))); 
				//make swap pawn available in some way
				this->isReadyToSwap = true;
			}

			if (x-1 == 0 && y-1 >= 0 && this->getPointerToBoard()->getPieceOnBoard(x-1, y-1) != nullptr)
			{
				this->addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x+1)));
				//make swap pawn available in some way
				this->isReadyToSwap = true;
			}

			if (x-1 == 0 && y+1 >= 0 && this->getPointerToBoard()->getPieceOnBoard(x-1, y+1) != nullptr)
			{
				this->addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x+1)));
				//make swap pawn available in some way
				this->isReadyToSwap = true;
			}
			//END OF FINAL STEP FOR WHITE PAWNS
		}
		else
		{
			if (x+1 < 7)
			{
				if (this->getPointerToBoard()->getPieceOnBoard(x+1,y) == nullptr)
				{
					this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x-1))); 
	
					if (!isMovedOnce && this->getPointerToBoard()->getPieceOnBoard(x+2,y) == nullptr)
					{
						this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x-2)));
					}
				}
			}
	
			if (x+1 < 7 && y-1 >= 0 && this->getPointerToBoard()->getPieceOnBoard(x+1,y-1) != nullptr)
			{
				if ((this->getPointerToBoard()->getPieceOnBoard(x+1,y-1)->getColour() != this->getColour()))
				{
					this->addPossiblePosition(Position((xCoordinate)(y-1),BOARD_SIZE-x-1));
				}
			}

			if (x+1 < 7 && y+1 <= 7 && this->getPointerToBoard()->getPieceOnBoard(x+1,y+1) != nullptr)
			{
				if ((this->getPointerToBoard()->getPieceOnBoard(x+1,y+1)->getColour() != this->getColour()))
				{
					this->addPossiblePosition(Position((xCoordinate)(y+1),BOARD_SIZE-x-1));	
				}
			}

			//FINAL STEP FOR BLACK PAWNS
			if (x+1 == 7 && this->getPointerToBoard()->getPieceOnBoard(x+1,y) == nullptr)
			{
				this->addPossiblePosition(Position((xCoordinate)y,(BOARD_SIZE-x-1))); 
				//make swap pawn available in some way
				this->isReadyToSwap = true;
			}

			if (x+1 == 7 && y-1 >= 0 && this->getPointerToBoard()->getPieceOnBoard(x+1, y-1) != nullptr)
			{
				this->addPossiblePosition(Position((xCoordinate)(y-1),(BOARD_SIZE-x-1)));
				//make swap pawn available in some way
				this->isReadyToSwap = true;
			}

			if (x+1 == 7 && y+1 >= 0 && this->getPointerToBoard()->getPieceOnBoard(x+1, y+1) != nullptr)
			{
				this->addPossiblePosition(Position((xCoordinate)(y+1),(BOARD_SIZE-x-1)));
				//make swap pawn available in some way
				this->isReadyToSwap = true;
			}
			//END OF FINAL STEP FOR BLACK PAWNS
		}

	//SWAP PAWN SHOULD BE ACTIVATED AT SOME POINT (when x-1 reaches 0 or (x-1,y-1 || x-1,y+1) are available
}	

bool Pawn::isPawnMovedOnce()
{
	return isMovedOnce;
}

void Pawn::setMovedOnce(bool _isMovedOnce)
{
	this->isMovedOnce = _isMovedOnce;
}

bool Pawn::isPawnReadyToSwap()
{
	return isReadyToSwap;
}

Pawn::Pawn(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition) :
	Piece(_pieceColour, _representation, _pointerToBoard, _currentPosition)
{
	this->isMovedOnce= false;
	this->isReadyToSwap = false;
}