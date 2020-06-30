#include "interface.h"
#include "classicalChess.h"

Interface::Interface(Board* board, History* history) {

	board_ = board;
	history_ = history;
}

void Interface::clear() {

	system("CLS");
}

void Interface::pause() {

	system("pause");
}

void Interface::drawBoard() {

	char white = 219;
	char black = 176;
	char color = white;

	for (int i = board_->height(), h = 1; i >= h; i--) {

		vector<string> row(3);

		row[0] += string(7, ' ');
		row[1] += "   " + to_string(i) + "   ";
		row[2] += string(7, ' ');

		for (int j = 1, w = board_->width(); j <= w; j++) {

			row[0] += string(6, color);
			row[2] += string(6, color);

			Square printing = board_->square(Position(i, j));

			if (printing.empty())
				row[1] += string(6, color);

			else
				row[1] += string(1, color) + " " + describe(printing, *board_) + " " + color;

			color = (color == white) ? black : white;
		}

		for (string j : row)
			cout << j << endl;

		color = (color == white) ? black : white;
	}

	cout << endl;
	cout << "         AA    BB    CC    DD    EE    FF    GG    HH" << endl;
	cout << endl;
}

void Interface::drawBoard(Position piece, vector<Position> targets) {

	char white = 219;
	char black = 176;
	char highlight = 177;
	char color = white;	

	for (int i = board_->height(), h = 1; i >= h; i--) {

		vector<string> row(3);

		row[0] += string(7, ' ');
		row[1] += "   " + to_string(i) + "   ";
		row[2] += string(7, ' ');

		for (int j = 1, w = board_->width(); j <= w; j++) {

			bool found = false;
			Square printing = board_->square(Position(i, j));

			for (Position k : targets) {

				if (k == printing.position()) {

					found = true;
					break;
				}
			}

			if (!found) {

				row[0] += string(6, color);
				row[2] += string(6, color);

				if (printing.empty())
					row[1] += string(6, color);

				else if (printing.position() == piece)
					row[1] += string(1, color) + "-" + describe(printing, *board_) + "-" + color;

				else
					row[1] += string(1, color) + " " + describe(printing, *board_) + " " + color;
			}

			else {

				row[0] += string(6, highlight);
				row[2] += string(6, highlight);

				if (printing.empty())
					row[1] += string(6, highlight);

				else
					row[1] += string(1, highlight) + " " + describe(printing, *board_) + " " + highlight;
			}

			color = (color == white) ? black : white;
		}

		for (string j : row)
			cout << j << endl;

		color = (color == white) ? black : white;
	}

	cout << endl;
	cout << "         AA    BB    CC    DD    EE    FF    GG    HH" << endl;
	cout << endl;
}

void Interface::startGame() {

	char turn = 0;
	bool checkmate = false;
	bool confirm = false;

	turn = alternatePlayer(turn);

	while (!checkmate) {

		confirm = false;

		while (!confirm) {

			string answer;
			Position piece;
			Position target;
			vector<Position> moves;

			clear();
			drawBoard();

			cout << endl;
			cout << "  Select piece to move: ";
			cin >> answer;

			piece = indentify(answer);

			if (!piece.valid() or board_->square(piece).color() != turn)
				break;

			moves = traceMoves(piece, *board_);

			clear();
			drawBoard(piece, moves);

			cout << endl;
			cout << "  Select move to make: ";
			cin >> answer;

			target = indentify(answer);

			if (!target.valid())
				break;

			for (Position i : moves) {

				if (target == i) {

					confirm = true;
					history_->append(notation(board_->square(piece), board_->square(target);
					board_->movePiece(piece, target);
					break;
				}
			}
		}

		if (confirm)
			turn = alternatePlayer(turn);
	}
}