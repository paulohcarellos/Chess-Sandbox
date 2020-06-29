#include "interface.h"

Interface::Interface(Board* board) {

	board_ = board;
}

void Interface::clear() {

	system("CLS");
}

void Interface::pause() {

	system("pause");
}

void Interface::drawBoard() {

	clear();

	for (int i = board_->height(); i >= 1; i--) {

		cout << " " << i << " - ";

		for (int j = 1, width = board_->width(); j <= width; j++) {

			Square square = board_->square(Position(i, j));

			cout << " " << print(square) << " ";
		}

		cout << endl;
	}

	cout << "      A   B   C   D   E   F   G   H" << endl;
}

void Interface::drawBoard(Position piece, vector<Position> targets) {

	clear();

	for (int i = board_->height(); i >= 1; i--) {

		cout << " " << i << " - ";

		for (int j = 1, width = board_->width(); j <= width; j++) {

			bool found = false;
			Square square = board_->square(Position(i, j));

			if (square.position() == piece) {

				cout << '[' << print(square) << ']';
				continue;
			}

			for (Position i : targets) {
				if (square.position() == i) {

					found = true;
					break;
				}
			}

			if (!found)
				cout << " " << print(square) << " ";

			else {

				if (square.empty())
					cout << (char)176 << (char)176 << (char)176 << (char)176;

				else
					cout << (char)176 << print(square) << (char)176;
			}
		}

		cout << endl;
	}

	cout << "      A   B   C   D   E   F   G   H" << endl;
}

string Interface::print(Square square) const {

	if (square.empty())
		return "  ";

	string out;

	if (square.color() == 1)
		out += 'W';

	if (square.color() == 2)
		out += 'B';

	if (square.type() == 1)
		out += 'P';

	if (square.type() == 2)
		out += 'R';

	if (square.type() == 3)
		out += 'H';

	if (square.type() == 4)
		out += 'B';

	if (square.type() == 5)
		out += 'Q';

	if (square.type() == 6)
		out += 'K';

	return out;
}
