#include "stdafx.h"
#include "Board.h"

Board::Board()
{
	this->setStatus(normal);
	this->setTurn(White);

	initBoard();
	initPieces();
}

Board::Board(Board const& other)
{
	copyBoard(other);
}

Board::~Board()
{
	clearMemory();
}

Board& Board::operator=(Board const& other)
{
	if (this != &other)
	{
		clearMemory();
		copyBoard(other);
	}

	return *this;
}

void Board::copyBoard(Board const& other)
{
	this->setStatus(other.status);
	this->setTurn(other.turn);

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->chessBoard[i][j] = other.chessBoard[i][j];
		}
	}
}

void Board::initBoard()
{
	//allocates memory for the pieces on the board
	chessBoard = new Piece**[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		chessBoard[i] = new Piece*[BOARD_SIZE];
	}

	//sets the positions of the "inactive" pieces or the empty spots on the board
	int counter = 2; //start after the first two rows
	for (int j = 6; j > 2; j--)
	{
		for (int k = 0; k < BOARD_SIZE; k++)
		{
			chessBoard[counter][k] = nullptr; 
		}
		counter++;	
	}
}

void Board::clearMemory()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			delete chessBoard[i][j];
		}
	}

	delete[] chessBoard;
	delete[] kings;
}

void Board::initPieces()
{
	initTowers();
	initKnights();
	initBishops();
	initQueens();
	initKings();
	initPawns();
}

void Board::initPawns()
{
	for (int i = 0; i < 16; i++)
	{
		if (i >= 8)
		{
			chessBoard[6][i - BOARD_SIZE ] = new Pawn(White, 'P', this, Position(xCoordinate(i - BOARD_SIZE), 2));
		}
		else
		{
			chessBoard[1][i] = new Pawn(Black, 'p', this, Position((xCoordinate)i, 7));
		}			
	}
}

void Board::initTowers()
{
	//whites
	chessBoard[7][0] = new Tower(White, 'T', this, Position(a,1));
	chessBoard[7][7] = new Tower(White, 'T', this, Position(h,1));

	//blacks
	chessBoard[0][0] = new Tower(Black, 't', this, Position(a,8));
	chessBoard[0][7] = new Tower(Black, 't', this, Position(h,8));
}

void Board::initKnights()
{
	//whites
	chessBoard[7][1] = new Knight(White, 'K', this, Position(b,1));
	chessBoard[7][6] = new Knight(White, 'K', this, Position(g,1));

	//blacks
	chessBoard[0][1] = new Knight(Black, 'k', this, Position(b,8));
	chessBoard[0][6] = new Knight(Black, 'k', this, Position(g,8));
}

void Board::initBishops()
{
	//whites
	chessBoard[7][2] = new Bishop(White, 'B', this, Position(c,1));
	chessBoard[7][5] = new Bishop(White, 'B', this, Position(f,1));

	//blacks
	chessBoard[0][2] = new Bishop(Black, 'b', this, Position(c,8));
	chessBoard[0][5] = new Bishop(Black, 'b', this, Position(f,8));
}

void Board::initQueens()	
{
	//white
	chessBoard[7][3] = new Queen(White, 'Q', this, Position(d,1));

	//black
	chessBoard[0][3] = new Queen(Black, 'q', this, Position(d,8));
}

void Board::initKings()
{
	//white
	kings = new King*[2];
	kings[0] = new King(White,'O',this,Position(e,1));
	chessBoard[7][4] = kings[WHITE_KING_ID];

	//black
	kings[1] = new King(Black,'o',this,Position(e,8));
	chessBoard[0][4] = kings[BLACK_KING_ID];
}

void Board::setTurn(Colour _turn)
{
	this->turn = _turn;
}

void Board::setStatus(BoardStatus _status)
{
	this->status = _status;
}

BoardStatus Board::getStatus() const
{
	return status;
}

Colour Board::getTurn() const
{
	return turn;
}

void Board::printBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		cout << BOARD_SIZE - i << "   ";
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (chessBoard[i][j] == nullptr)
			{
				cout << "- ";
			}
			else
			{
				cout << chessBoard[i][j]->getRepresentation() << " ";
			}
			
		}
		cout << endl;
	}

	cout << "\n    " << "A B C D E F G H" << endl;
}

void Board::getCellPosition(int i, int j)
{
	if (chessBoard[i][j] != nullptr)
	{
		cout << xCoord[chessBoard[i][j]->getPosition().getX()] << chessBoard[i][j]->getPosition().getY();
	}
	else
	{
		cout << "- ";
	}
}

void Board::printAllPositions()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int k = 0; k < BOARD_SIZE; k++)
		{
			this->getCellPosition(i,k);
			cout << " ";
		}
		cout << endl;
	}
}

void Board::move(Position oldPos, Position newPos) 
{
	if ((oldPos.getX() > BOARD_SIZE) || (oldPos.getX() < 0) || (oldPos.getY() > BOARD_SIZE) || (oldPos.getY() < 0))
	{
		cout << "Invalid start position: " << oldPos << endl;
		cout << "Enter new starting position: " << endl;
		return;
	}
	else if ((newPos.getX() > BOARD_SIZE) || (newPos.getX() < 0) || (newPos.getY() > BOARD_SIZE) || (newPos.getY() < 0))
	{
		cout << "Invalid end position: " << oldPos << endl;
		cout << "Enter new end position: " << endl;
		return;
	}
	else if ((this->getPieceOnBoard(oldPos) == nullptr) || (this->getPieceOnBoard(oldPos)->getColour() != this->getTurn()))
	{
		cout << "Invalid start position: " << oldPos << endl;
		cout << "Enter new starting position: " << endl;
		return;
	}
	
	//resets the current positions array
	this->getPieceOnBoard(oldPos)->resetPiece();

	//if all above checks passed - we can calculate possible new position and confirm it;
	this->getPieceOnBoard(oldPos)->calculatePossiblePositions();

	//by here we will have all the possibles calculated
	int possibleLength = getPieceOnBoard(oldPos)->getPossiblePositionsSize();
	
	bool isAvailable = false;

	for (int i = 0; i <= possibleLength; i++)
	{
		if (newPos == getPieceOnBoard(oldPos)->getPossiblePositionAt(i))
		{
			isAvailable = true;
			break;
		}
	}
	
	if (isAvailable && this->getStatus() == normal)
	{
		Piece * tempNewPos = this->getPieceOnBoard(newPos);

		//setting the pointer from new to point to old and also set the position of the new
		if (this->getPieceOnBoard(newPos) != nullptr)
		{
			this->getPieceOnBoard(newPos)->resetPiece(); //new position, all possibles are cleared
		}

		chessBoard[BOARD_SIZE - newPos.getY()][newPos.getX()] = chessBoard[BOARD_SIZE - oldPos.getY()][oldPos.getX()];
		this->getPieceOnBoard(newPos)->setPosition(newPos);
		chessBoard[BOARD_SIZE - oldPos.getY()][oldPos.getX()] = nullptr;
		
		//PAWN SPECIAL
		//we check if the piece is a Pawn, if it is, we mark it as moved (so it can no longer make double step)
		if (dynamic_cast<Pawn*>(this->getPieceOnBoard(newPos)))
			dynamic_cast<Pawn*>(this->getPieceOnBoard(newPos))->setMovedOnce(true);

		//if the pawn has reached the final row, then we can promote it to another piece
		if (dynamic_cast<Pawn*>(this->getPieceOnBoard(newPos)) &&
			dynamic_cast<Pawn*>(this->getPieceOnBoard(newPos))->isPawnReadyToSwap())
		{
			this->pawnPromotion(newPos);
		}
		//END OF PAWN SPECIAL
		
		//KING SPECIAL	
		if (this->getTurn() == White)
		{
			this->sandBoxCheckVerify(WHITE_KING_ID);	
		}
		else
		{
			this->sandBoxCheckVerify(BLACK_KING_ID);	
		}

		if (this->status == check)
		{
			cout << "Invalid move, your king will be in check!" << endl;
			chessBoard[BOARD_SIZE - oldPos.getY()][oldPos.getX()] = chessBoard[BOARD_SIZE - newPos.getY()][newPos.getX()];
			this->getPieceOnBoard(oldPos)->setPosition(oldPos);
			chessBoard[BOARD_SIZE - newPos.getY()][newPos.getX()] = tempNewPos;
			this->setStatus(normal);
			return;
		}
		//END OF KING SPECIAL

		this->fullCheckVerification(turn); //can be optimized

		if (getPieceOnBoard(newPos)->getColour() == White)
		{
			this->setTurn(Black);
		}
		else
		{
			this->setTurn(White);
		}
	}
	else if (isAvailable && this->getStatus() == check) //sandbox one move
	{
		Piece * temp = this->getPieceOnBoard(newPos); //newPosition pointer

		chessBoard[BOARD_SIZE - newPos.getY()][newPos.getX()] = chessBoard[BOARD_SIZE - oldPos.getY()][oldPos.getX()]; 
		this->getPieceOnBoard(newPos)->setPosition(newPos);
		chessBoard[BOARD_SIZE - oldPos.getY()][oldPos.getX()] = nullptr;
		
		this->setStatus(normal);

		if (this->getTurn() == White)
		{
			this->sandBoxCheckVerify(WHITE_KING_ID);
		}
		else
		{
			this->sandBoxCheckVerify(BLACK_KING_ID);
		}
		
		if (this->getStatus() == check)
		{
			cout << "Invalid move! Still in Check!" << endl;
			
			chessBoard[BOARD_SIZE - oldPos.getY()][oldPos.getX()] = chessBoard[BOARD_SIZE - newPos.getY()][newPos.getX()];
			this->getPieceOnBoard(oldPos)->setPosition(oldPos);
			chessBoard[BOARD_SIZE - newPos.getY()][newPos.getX()] = temp;
		}
		else
		{
			if (getPieceOnBoard(newPos)->getColour() == White)
			{
				this->setTurn(Black);
			}
			else
			{
				this->setTurn(White);
			}

			this->setStatus(normal);
		}
	}
	else
	{
		cout << "Invalid end position: " << newPos << endl;
		cout << "Enter new end position: " << endl;
	}
} 

void Board::fullCheckVerification(Colour turn)
{
	int kingIndex;
	if (turn == White)
	{
		kingIndex = BLACK_KING_ID;
	}
	else
	{
		kingIndex = WHITE_KING_ID;
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (chessBoard[i][j] != nullptr)
			{
				if (chessBoard[i][j]->getColour() == turn)
				{
					chessBoard[i][j]->resetPiece(); //resets all possible positions, before calculating them again
					chessBoard[i][j]->calculatePossiblePositions(); 

					for (int k = 0; k <= chessBoard[i][j]->getPossiblePositionsSize(); k++)
					{
						if (chessBoard[i][j]->getPossiblePositionAt(k) == kings[kingIndex]->getPosition())
						{
							this->setStatus(check);
							this->mateVerification(turn, i, j, kingIndex);
							return;
						}
					}
				}
			}
		}
	}
}
                                             
void Board::mateVerification(Colour turn, int i, int j,  int kingIndex) //kingIndex is the index of the king in check.
{				
	bool mateFlag = true;
	
	kings[kingIndex]->resetPiece();
	kings[kingIndex]->calculatePossiblePositions();

	for (int m = 0; m <= kings[kingIndex]->getPossiblePositionsSize(); m++)
	{
		//coordinates
		int possibleX = kings[kingIndex]->getPossiblePositionAt(m).getX(); 
		int possibleY = BOARD_SIZE - kings[kingIndex]->getPossiblePositionAt(m).getY(); 

		int currX = kings[kingIndex]->getPosition().getX(); 
		int currY = BOARD_SIZE - kings[kingIndex]->getPosition().getY();

		Piece * temp = chessBoard[possibleY][possibleX]; //newPosition pointer
										

		if (chessBoard[possibleY][possibleX] != nullptr)
		{										
			Position tempNewPos(chessBoard[possibleY][possibleX]->getPosition());	
		    Position tempOldPos(kings[kingIndex]->getPosition());

			chessBoard[possibleY][possibleX] = chessBoard[currY][currX];
			chessBoard[possibleY][possibleX]->setPosition(tempNewPos);
			chessBoard[currY][currX] = nullptr;
		
			this->setStatus(normal);
			this->sandBoxCheckVerify(kingIndex);	

			if (this->getStatus() == normal)
			{
				chessBoard[currY][currX] = chessBoard[possibleY][possibleX];
				chessBoard[currY][currX]->setPosition(tempOldPos);
				chessBoard[possibleY][possibleX] = temp;
				mateFlag = false;
				this->setStatus(check);
				break; //maybe even return
			}
			else
			{
				chessBoard[currY][currX] = chessBoard[possibleY][possibleX];
				chessBoard[currY][currX]->setPosition(tempOldPos);
				chessBoard[possibleY][possibleX] = temp;
			}
		}
		else //if its nullptr
		{
			Position tempOldPos(kings[kingIndex]->getPosition());
			Position tempNewPos((xCoordinate)possibleX,(possibleY + BOARD_SIZE));
			chessBoard[possibleY][possibleX] = chessBoard[currY][currX];

			chessBoard[possibleY][possibleX]->setPosition(tempNewPos);
		
			chessBoard[currY][currX] = nullptr;
			this->setStatus(normal);

			this->sandBoxCheckVerify(kingIndex); 
			
			if (this->getStatus() == normal)
			{
				chessBoard[currY][currX] = chessBoard[possibleY][possibleX];
				chessBoard[currY][currX]->setPosition(tempOldPos);
				
				chessBoard[possibleY][possibleX] = temp;
				mateFlag = false;
				this->setStatus(check);
				break;
			}
			else
			{
				chessBoard[currY][currX] = chessBoard[possibleY][possibleX];
				chessBoard[currY][currX]->setPosition(tempOldPos);
				
				chessBoard[possibleY][possibleX] = temp;
			}
		}
	}
	//second part
	for (int p = 0; p < BOARD_SIZE; p++)
	{
		for (int n = 0; n < BOARD_SIZE; n++)
		{
			if (chessBoard[p][n] != nullptr)
			{                                                  
				if (chessBoard[p][n]->getColour() != turn && !(chessBoard[p][n]->getPosition() == kings[kingIndex]->getPosition()))
				{
					chessBoard[p][n]->resetPiece();
					chessBoard[p][n]->calculatePossiblePositions();
						                 
					for (int k = 0; k <= chessBoard[p][n]->getPossiblePositionsSize(); k++)
					{
						if (chessBoard[p][n]->getPossiblePositionAt(k) == chessBoard[i][j]->getPosition())
						{
							Piece * temp = chessBoard[i][j]; //newPosition pointer
								
							Position tempNewPos = chessBoard[i][j]->getPosition(); 
							Position tempOldPos = chessBoard[p][n]->getPosition();

							chessBoard[i][j] = chessBoard[p][n];
							chessBoard[i][j]->setPosition(tempNewPos);
							chessBoard[p][n] = nullptr;
		
							this->setStatus(normal);

							if (this->getTurn() == White)
							{		
								this->sandBoxCheckVerify(BLACK_KING_ID);	 
							}
							else
							{
								this->sandBoxCheckVerify(WHITE_KING_ID);
							}
		
							if (this->getStatus() == check)
							{
								//Still in Check!
								chessBoard[p][n] = chessBoard[i][j];
								chessBoard[p][n]->setPosition(tempOldPos);
								chessBoard[i][j] = temp;
							}
							else
							{
								this->setStatus(check);
								mateFlag = false;
								break;
							}
						}
					}
				} 
			}
		}
	}														

	if (mateFlag)
	{
		this->setStatus(checkmate);
	}
}

//check for castling

Piece* Board::getPieceOnBoard(Position pos)
{
	return chessBoard[BOARD_SIZE - pos.getY()][pos.getX()];
}

Piece* Board::getPieceOnBoard(int x, int y)
{
	return chessBoard[x][y];
}

void Board::pawnPromotion(Position pawnPosition)
{
	bool flag = true;
	while (flag)
	{
		char userInput;
		cout << "You can promote your pawn!" << endl;
		cout << "Select to which piece (use capital letters only): " << endl;
		cout << "Q = Queen | T = Tower | K = Knight | B = Bishop" << endl;
		cin >> userInput;

		switch (userInput)
		{
		case 'Q':
			if (turn == White)
			{
				chessBoard[BOARD_SIZE - pawnPosition.getY()][pawnPosition.getX()] = new Queen(White,'Q',this,pawnPosition);
			}
			else
			{
				chessBoard[BOARD_SIZE - pawnPosition.getY()][pawnPosition.getX()] = new Queen(Black,'q',this,pawnPosition);
			}
			
			flag = false;
			break;
		case 'T': 
			if (turn == White)
			{
				chessBoard[BOARD_SIZE - pawnPosition.getY()][pawnPosition.getX()] = new Tower(White,'T',this,pawnPosition);
			}
			else
			{
				chessBoard[BOARD_SIZE - pawnPosition.getY()][pawnPosition.getX()] = new Tower(Black,'t',this,pawnPosition);
			}
			flag = false;
			break;
		case 'K':
			if (turn == White)
			{
				chessBoard[BOARD_SIZE - pawnPosition.getY()][pawnPosition.getX()] = new Knight(White,'K',this,pawnPosition);
			}
			else
			{
				chessBoard[BOARD_SIZE - pawnPosition.getY()][pawnPosition.getX()] = new Knight(Black,'k',this,pawnPosition);
			}
			flag = false;
			break;
		case 'B':
			if (turn == White)
			{
				chessBoard[BOARD_SIZE - pawnPosition.getY()][pawnPosition.getX()] = new Bishop(White,'B',this,pawnPosition);
			}
			else
			{
				chessBoard[BOARD_SIZE - pawnPosition.getY()][pawnPosition.getX()] = new Bishop(Black,'b',this,pawnPosition);
			}
			flag = false;
			break;
		
		}
	}
}

void Board::sandBoxCheckVerify(int kingId)
{
	Colour flag;
	(kingId == BLACK_KING_ID) ? flag = White : flag = Black;
	for (int c = 0; c < BOARD_SIZE; c++) 
	{
		for (int v = 0; v < BOARD_SIZE; v++) 
		{
			if(chessBoard[c][v] != nullptr)
			{
				if(chessBoard[c][v]->getColour() == flag)
				{
					chessBoard[c][v]->resetPiece();
					chessBoard[c][v]->calculatePossiblePositions(); 

					for (int z = 0; z <= chessBoard[c][v]->getPossiblePositionsSize(); z++)
					{
						if (chessBoard[c][v]->getPossiblePositionAt(z) == kings[kingId]->getPosition())
						{
							this->setStatus(check);
							return;
						}
					}
				}
			}
		}
	} 
}