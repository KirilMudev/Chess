#include "stdafx.h"
#include "Piece.h"
#include "assert.h"
#include "Board.h"

Piece::Piece()
{
	this->representation = '-';
	this->possiblePositions = new Position[1];
	this->pointerToBoard = nullptr;
}

Piece::Piece(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition)
{
	this->setPieceColour(_pieceColour);
	this->setPosition(_currentPosition);
	this->setRepresentation(_representation);
	this->pointerToBoard = _pointerToBoard;
	this->initPossiblePositions(); //just initializes new positions
}

Piece::Piece(Piece const& other)
{
	this->copy(other);
}

Piece::~Piece()
{
	this->clearMemory();
}

Piece& Piece::operator=(Piece const& other)
{
	if (this != &other)
	{
		this->clearMemory();
		this->copy(other);
	}

	return *this;
}

void Piece::resetPiece()
{
	delete[] this->possiblePositions;
	this->possiblePositions = new Position[10];
	this->setPossiblePositionsSize(-1);
	this->setPossiblePositionsCapacity(10);
}

void Piece::clearMemory()
{
	delete[] this->possiblePositions;
}

void Piece::initPossiblePositions()
{
	this->possiblePositions = new Position[10];
	this->possiblePositionsSize = -1;
	this->possiblePositionsCapacity = 10;
}

void Piece::copy(Piece const& other)
{
	this->setRepresentation(other.representation);
	this->setPieceColour(other.pieceColour);
	this->setPosition(other.currentPosition);
	this->setPossiblePositionsCapacity(other.possiblePositionsCapacity);
	this->setPossiblePositionsSize(other.possiblePositionsSize);
	this->setPointerToBoard(other.pointerToBoard);

	//this doesn't look rational, as different pieces will have different possible positions (when we use '=' on the chessboard)
	//still leaving it for now
	this->possiblePositions = new Position[possiblePositionsCapacity];

	for (int i = 0; i <= this->possiblePositionsSize; i++)
	{
		this->possiblePositions[i] = other.possiblePositions[i];
	}
}

	
void Piece::addPossiblePosition(Position const& _newPosition)
{
	if (this->possiblePositionsSize == this->possiblePositionsCapacity-1)
	{
		this->resizePossiblePositions();
	}

	this->possiblePositionsSize++;
	this->possiblePositions[possiblePositionsSize] = _newPosition;
}

void Piece::resizePossiblePositions()
{
	this->possiblePositionsCapacity *= RESIZE_COEF;

	Position* tempPossiblePositions = new Position[possiblePositionsCapacity];

	for (int i = 0; i <= possiblePositionsSize; i++)
	{
		tempPossiblePositions[i] = possiblePositions[i]; 
	}
		
	delete[] this->possiblePositions;
	this->possiblePositions = tempPossiblePositions;
}

void Piece::setPieceColour(Colour _colour)
{
	this->pieceColour = _colour;
}

void Piece::setPosition(xCoordinate _x, int _y)
{
	currentPosition.setX(_x);
	currentPosition.setY(_y);
} 

void Piece::setPosition(Position const& _currentposition)
{
	currentPosition.setX(_currentposition.getX());
	currentPosition.setY(_currentposition.getY());
}

Colour Piece::getColour() const
{
	return pieceColour;
}

Position Piece::getPosition() const
{
	return currentPosition;
}

void Piece::setPossiblePositionsSize(int _newSize)
{
	this->possiblePositionsSize = _newSize;
}

int Piece::getPossiblePositionsSize() const
{
	return possiblePositionsSize;
}

void Piece::setPossiblePositionsCapacity(int _newCapacity)
{
	this->possiblePositionsCapacity = _newCapacity;
}

int Piece::getPossiblePositionsCapacity() const
{
	return possiblePositionsCapacity;
}

void Piece::setRepresentation(char _representation)
{
	this->representation = _representation;
}

char Piece::getRepresentation() const
{
	return representation;
}
	
//testing purpose 
void Piece::printPosition()
{
	cout << currentPosition.getX() << currentPosition.getY() << endl;
} 

Position& Piece::getPossiblePositionAt(int index)
{
	assert(index >= 0 && index <= possiblePositionsSize);
	return possiblePositions[index];
}

Board* Piece::getPointerToBoard() const
{
	return pointerToBoard;
}

void Piece::setPointerToBoard(Board * _pointerToBoard)
{
	pointerToBoard = _pointerToBoard;
}

