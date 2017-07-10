#pragma once
#include "Position.h"

const int RESIZE_COEF = 2;
const int BOARD_SIZE = 8; //should be used in all the "calculatePosition" methods (and basically everywhere when magic 8s are used.)
const int BLACK_KING_ID = 1;
const int WHITE_KING_ID = 0;

enum Colour {White, Black};
static const char* Colours[] = {"White","Black"};

class Board;

class Piece
{
	Board * pointerToBoard;
	char representation; 
	Colour pieceColour;
	Position currentPosition; 
	Position* possiblePositions; //contains the positions where the piece can go at the current moment
	int possiblePositionsSize;
	int possiblePositionsCapacity;

	void resizePossiblePositions();
	void clearMemory();
	void copy(Piece const& other);

public:
	Piece();
	Piece(Colour _pieceColour, char _representation, Board * _pointerToBoard, Position& _currentPosition);
	Piece(Piece const& other);
	~Piece();
	Piece& operator=(Piece const& other);

	void resetPiece(); //clears the array and allocates new memory
	void initPossiblePositions(); //array initialization
	void addPossiblePosition(Position const& _newPosition);

	void setPossiblePositionsSize(int _newSize);
	void setPossiblePositionsCapacity(int _newCapacity);
	void setPieceColour(Colour _colour);
	void setPosition(xCoordinate _x, int _y);
	void setPosition(Position const& _currentposition);
	void setPointerToBoard(Board * _pointerToBoard);

	Colour getColour() const;
	Position getPosition() const;
	void setRepresentation(char _representation);
	char getRepresentation() const;
    int getPossiblePositionsSize() const;
	int getPossiblePositionsCapacity() const;
	Position& getPossiblePositionAt(int index);
	Board* getPointerToBoard() const;
	
	//PURE VIRTUAL FUNCTION, different for each type, adds all the possible positions in the array "possiblePositions"
	virtual void calculatePossiblePositions() = 0; 
	
	//Helpers and printing methods
	void printPosition();
	void printPiece();
};

