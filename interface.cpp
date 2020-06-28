#include "interface.h"

inline void Interface::clear() {

	system("CLS");
}

inline void Interface::pause() {

	system("pause");
}

void Interface::drawBoard() {

	for (int i = 7; i >= 0; i--) {

		cout << " " << i + 1 << " - " ;

		for (int j = 0; j < 8; j++) {

			Tile print = board_[i][j];

			cout << " " << print.color() << print.type() << " ";
		}

		cout << endl;
	}

	cout << "      A   B   C   D   E   F   G   H" << endl;
}

void Interface::drawBoard(Position piece, vector<Position> targets) {

	for (int i = 7; i >= 0; i--) {

		cout << " " << i + 1 << " - ";

		for (int j = 0; j < 8; j++) {

			bool found = false;
			Tile print = board_[i][j];
			Position location(i, j);

			if (location == piece) {

				cout << '[' << print.color() << print.type() << ']';
				continue;
			}

			for (Position i : targets) {
				if (location == i) {

					found = true;
					break;
				}
			}

			if (!found)
				cout << " " << print.color() << print.type() << " ";

			else {

				if (print.empty())
					cout << (char)176 << (char)176 << (char)176 << (char)176;

				else
					cout << (char)176 << print.color() << print.type() << (char)176;
			}
				

		}

		cout << endl;
	}

	cout << "      A   B   C   D   E   F   G   H" << endl;
}

void Interface::start() {

	char turn = 'W';
	bool mate = false;
	bool confirm = false;

	while (!mate) {
		while (!confirm) {

			string answer;
			Position piece;
			Position target;
			Tile selected;

			vector<Position> targets;

			clear();
			drawBoard();

			cout << endl;
			cout << " Select piece to move: ";
			cin >> answer;

			piece = Position(answer);

			if (!piece.valid()) {

				cout << " Invalid position\n" << endl;
				pause();
				break;
			}

			selected = board_[piece.x()][piece.y()];

			if (selected.color() == turn and !selected.empty()) {

				targets = selected.moves();

				for (Position i : targets)
					cout << i.x() << " " << i.y() << endl;

				drawBoard(piece, targets);

				cout << endl;
				cout << " Select move: ";
				cin >> answer;

				target = Position(answer);

				for (Position i : targets) {

					if (target == i) {

						confirm = true;
						move(piece, target);

					}
				}

				if (!confirm) {

					cout << " Invalid move" << endl;
					pause();
				}
			}

			else {

				cout << " Invalid piece" << endl;
				pause();
			}
		}

		turn = (turn == 'W') ? 'B' : 'W';
	}
}

void Interface::move(Position piece, Position target) {

	cout << "todo" << endl;
}

void Interface::select(Position piece) {

	cout << "todo" << endl;
}
