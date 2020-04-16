#include <iostream>

using namespace std;

namespace ttt{
	enum class State {Empty, Player1, Player2};

	State board[3][3];

	int count_moves;

	void DrawBoard() {
		for (int y = 0; y < 3; y++)
		{
			if (y == 0) cout << "  0 1 2" << endl;
			for (int x = 0; x < 3; x++) {
				if (x == 0)
					cout << y << " ";

				switch (board[x][y]) {
					case State::Empty:
						cout << ". ";
						break;
					case State::Player1:
						cout << "X ";
						break;
					case State::Player2:
						cout << "O ";
						break;
				}
			}
			cout << endl;
		}
	}

	void ClearScreen() {
		system("cls");

		DrawBoard();
	}

	void Play(State player) {
		int x, y;

		do {
			ClearScreen();		

			cout << endl << (player == State::Player1 ? "Player 1\n" : "Player 2\n") << endl;
			cout << "X: ";
			cin >> x;
			cout << "Y: ";
			cin >> y;
		} while (x > 2 || x < 0 || y > 2 || y < 0 || (board[x][y] != State::Empty));

		board[x][y] = player;

		count_moves++;
	}

	bool Win(State player) {
		int ix[3]{}, iy[3]{}, id[2]{};

		for(int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				if (board[x][y] == player) {
					ix[x]++;
					iy[y]++;

					if (x == y) id[0]++;
					if (x == 2 - y) id[1]++;
				}
			
		for (int i = 0; i < 3; i++)
			if (ix[i] == 3 || iy[i] == 3)
				return true;
		
		if (id[0] == 3 || id[1] == 3)
			return true;

		return false;
	}
}
