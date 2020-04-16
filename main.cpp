#include "tictactoe.h"

using namespace std;
using namespace ttt;

int main(void) {

	int turn = 0;

	const State player[2] = { State::Player1, State::Player2 };

	cout << "@@@ START GAME @@@";
	cin.get();

	ClearScreen();

	do {
		Play(player[turn]);
		if (Win(player[turn]))
		{
			ClearScreen();

			cout << (player[turn] == State::Player1 ? "\nPLAYER 1 " : "\nPLAYER 2 ") << "IS WINNER!!!" << endl;
			break;
		}

		turn++;
		turn %= 2;
	} while (count_moves < 9);

	return 0;
}