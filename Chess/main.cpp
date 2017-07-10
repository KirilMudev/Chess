#include "stdafx.h"
#include "iostream"
#include "Board.h"

using namespace std;

void playGame();
void menu();

int main()
{	
	//Just compile and test. (it's not fully stable, but works in general)
	menu();
	
	return 0;
}

void playGame()
{
	system("cls");
	Board nBord;
	Position startPos;
	Position endPos;
	cout << "Chessboard initialized! Good luck and have fun!" << endl;
	nBord.printBoard();
	cout << "________________________________________" << endl;
	cout << endl;
	int counter = 0;
	while (nBord.getStatus() != checkmate)
	{
		cout << Colours[nBord.getTurn()] << "'s turn." << endl;
		cout << "Enter starting and end position: ";
		cin >> startPos;
		cin >> endPos;
		counter++;
		if(counter == 4)
		{		
			system("cls");
			counter = 0;
		}
		nBord.move(startPos, endPos);

		if (nBord.getStatus() == check)
			cout << Colours[nBord.getTurn()] << "'s king is in check!" << endl;
		
		nBord.printBoard();
		cout << "________________________________________" << endl;
	}

	if (nBord.getTurn() == White)
	{
		cout << "CHECKMATE! The Black player wins!" << endl;
		cout << "------------- END OF GAME -------------" << endl;
	}
	else
	{
		cout << "CHECKMATE! The White player wins!" << endl;
		cout << "------------- END OF GAME -------------" << endl;
	}
}

void menu()
{
	cout << "Chess C++ edition" << endl;
	cout << "________________________________________" << endl;
	cout << "Menu: " << endl;
	cout << "1. Start a new game" << endl;
	cout << "2. Exit" << endl;
	char userInput;
	cout << "Please select action: " << endl;
	cin >> userInput;
	switch (userInput)
	{
		case '1' : playGame(); break;
		case '2' : return; break;	
	}
}