//
//
// Tic Tac Toe Game
//
//


#include <iostream>
using namespace std;

char Position[10] = { '0','1','2','3','4','5','6','7','8','9' }; // Vector with mark options
const char OldPosition[10] = { '0','1','2','3','4','5','6','7','8','9' }; // Default state of vector with mark options

// ------------- Print the game table function
void PrintTable() {
	system("cls");
	cout << "\n\n\tTic Tac Toe Game\n\n";

	cout << "   Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "\t     |     |     " << endl;
	cout << "\t  " << Position[1] << "  |  " << Position[2] << "  |  " << Position[3] << endl;

	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;

	cout << "\t  " << Position[4] << "  |  " << Position[5] << "  |  " << Position[6] << endl;

	cout << "\t_____|_____|_____" << endl;
	cout << "\t     |     |     " << endl;

	cout << "\t  " << Position[7] << "  |  " << Position[8] << "  |  " << Position[9] << endl;

	cout << "\t     |     |     " << endl << endl;
}

// ------------ Function checker if we got a winner and return 1 or -1 if it's tie
int CheckWinner() {
	if (Position[1] == Position[2] && Position[2] == Position[3])

		return 1;
	else if (Position[4] == Position[5] && Position[5] == Position[6])

		return 1;
	else if (Position[7] == Position[8] && Position[8] == Position[9])

		return 1;
	else if (Position[1] == Position[4] && Position[4] == Position[7])

		return 1;
	else if (Position[2] == Position[5] && Position[5] == Position[8])

		return 1;
	else if (Position[3] == Position[6] && Position[6] == Position[9])

		return 1;
	else if (Position[1] == Position[5] && Position[5] == Position[9])

		return 1;
	else if (Position[3] == Position[5] && Position[5] == Position[7])

		return 1;
	else if (Position[1] != '1' && Position[2] != '2' && Position[3] != '3'
		&& Position[4] != '4' && Position[5] != '5' && Position[6] != '6'
		&& Position[7] != '7' && Position[8] != '8' && Position[9] != '9')

		return 0;
	else
		return -1;
}

// ------------ Function to swap Player1 with Player2 during the game
void PlayerSwap(int& _PlayerInTurn, int _PlayersList[2]) {
	_PlayerInTurn = (_PlayerInTurn == _PlayersList[0]) ? _PlayersList[1] : _PlayersList[0];
}

// ----------- Main function, the program entry point
void main()
{
	int Option;
	do {
		int PlayersList[2] = { 1,2 }; // Declarete players
		int PlayerInTurn = 1;
		int PlayerChoice;
		char PlayerMark;
		int Winner;
		do {
			PrintTable();
		label:
			cout << "   Player " << PlayerInTurn << " choose your option: ";
			cin >> PlayerChoice;
			PlayerMark = (PlayerInTurn % 2) == 1 ? 'X' : 'O';
			if (PlayerChoice == 1 && Position[1] == '1')

				Position[1] = PlayerMark;
			else if (PlayerChoice == 2 && Position[2] == '2')

				Position[2] = PlayerMark;
			else if (PlayerChoice == 3 && Position[3] == '3')

				Position[3] = PlayerMark;
			else if (PlayerChoice == 4 && Position[4] == '4')

				Position[4] = PlayerMark;
			else if (PlayerChoice == 5 && Position[5] == '5')

				Position[5] = PlayerMark;
			else if (PlayerChoice == 6 && Position[6] == '6')

				Position[6] = PlayerMark;
			else if (PlayerChoice == 7 && Position[7] == '7')

				Position[7] = PlayerMark;
			else if (PlayerChoice == 8 && Position[8] == '8')

				Position[8] = PlayerMark;
			else if (PlayerChoice == 9 && Position[9] == '9')

				Position[9] = PlayerMark;
			else
			{
				cout << "   Invalid move ";
				cin.ignore();
				cin.get();
				goto label;
			}
			Winner = CheckWinner();
			PlayerSwap(PlayerInTurn, PlayersList);
		} while (Winner == -1);
		PrintTable();
		if (Winner == 1) {
			PlayerSwap(PlayerInTurn, PlayersList);
			cout << "--------- \aPlayer " << PlayerInTurn << " it's the winner! ---------" << endl;
			cout << "  Press ENTER key to continue!" << endl;
		}
		else {
			cout << " --------- \aGame draw! ---------" << endl;
			cout << "  Press ENTER key to continue!" << endl;

		}
		cin.ignore();
		cin.get();
		for (int i = 1; i < 10; ++i)
			Position[i] = OldPosition[i];
		cout << " \tDo you want a remach? ";
		cout << "Enter [1] to play again for revange or [0] to quit the game: ";
		cin >> Option;
		do {
			if (Option != 1 && Option != 0) {
				cout << " --------- \aInvalid input! ---------" << endl;
				cout << "Retype your option: ";
				cin >> Option;
			}

		} while (Option != 1 && Option != 0);
	} while (Option == 1);
	if (Option == 0)
		system("exit");
}

