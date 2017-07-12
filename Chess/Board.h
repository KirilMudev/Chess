#pragma once
#include "Piece.h"
#include "Pawn.h"
#include "Tower.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

enum BoardStatus {normal, check, checkmate};


class Board
{
	Piece *** chessBoard;
	BoardStatus status; 
	Colour turn; 

	King** kings;

	void initBoard();
	void clearMemory();

	void initPieces();
	void initPawns();
	void initTowers();
	void initKnights();
	void initBishops();
	void initQueens();
	void initKings();

	void setTurn(Colour _turn);
	void setStatus(BoardStatus _status);
	void copyBoard(Board const& other);

public:
	
	Board();
	Board(Colour _turn);
	Board(Board const& other); 
	~Board();
	Board& operator=(Board const& other);
	
	BoardStatus getStatus() const;
	Colour getTurn() const;
	Piece* getPieceOnBoard(Position pos); // Translates user input to matrix coordinates (and gets the piece on given position).
	Piece* getPieceOnBoard(int x, int y); // Uses matrix coordinates to reach a certain piece.

	//The methods below are not well optimised and haven't been heavily tested, but they seem to pass a certain amount of tests.

	void move(Position oldPos, Position newPos); // Main logic of the game is here. (more info inside)
	void fullCheckVerification(Colour _nextTurn); // Logic to determine check/mate.
	void mateVerification(Colour turn, int checkGiverX, int checkGiverY,  int kingIndex); // Heavy logic, including sandboxing a move and determining if a "mate" is present on the board. 
	void pawnPromotion(Position pawnPosition); // Used when a pawn reaches the end of the board in order to promote it.
	
	//Helper methods and printing.
	void printBoard();
	void getCellPosition(int i, int j);
	void printAllPositions();
	void sandBoxCheckVerify(int kingId);
};

