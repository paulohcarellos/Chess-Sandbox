#include "interface.h"

Interface::Interface(ClassicalChess& x) {

	root_ = &x;
}

void Interface::draw_board() {

	bool foreground_white = true;
	Tile printing;
	
	cout << endl;

	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {

			if (j % 2 == 0)
				cout << "      ";

			if (j % 2 == 1)
				cout << "  " << i + 1 << "   ";

			for (int k = 0; k < 8; k++) {

				printing = root_->tile(i, k);

				if ((i % 2 == 0 and k % 2 == 0) or (i % 2 == 1 and k % 2 == 1))
					foreground_white = true;

				else
					foreground_white = false;

				if (j % 2 == 0) {

					if (foreground_white)
						cout << char(176) << char(176) << char(176) << char(176) << char(176) << char(176);

					else
						cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178);
				}

				else {

					if (foreground_white)
						cout << char(176);

					else
						cout << char(178);

					if (printing.color() == WHITE)
						cout << " W";

					if (printing.color() == BLACK)
						cout << " B";

					if (printing.type() == PAWN)
						cout << "P ";

					if (printing.type() == ROOK)
						cout << "R ";

					if (printing.type() == HORSE)
						cout << "H ";

					if (printing.type() == BISHOP)
						cout << "B ";

					if (printing.type() == QUEEN)
						cout << "Q ";

					if (printing.type() == KING)
						cout << "K ";

					if (printing.type() == NONE and printing.color() == NONE) {

						if (foreground_white)
							cout << char(176) << char(176) << char(176) << char(176);

						else
							cout << char(178) << char(178) << char(178) << char(178);
					}

					if (foreground_white)
						cout << char(176);

					else
						cout << char(178);
				}
			}

			cout << endl;
		}	
	}

	cout << endl;
	cout << "        A     B     C     D     E     F     G     H " << endl;
}

void Interface::draw_moves(Tile piece, vector<Tile> moves) {

	bool foreground_white = true;
	bool inside;
	Tile printing;

	cout << endl;

	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {

			if (j % 2 == 0)
				cout << "      ";

			if (j % 2 == 1)
				cout << "  " << i + 1 << "   ";

			for (int k = 0; k < 8; k++) {

				printing = root_->tile(i, k);
				inside = false;

				for (Tile l : moves) {

					if (l == printing)
						inside = true;
				}

				if ((i % 2 == 0 and k % 2 == 0) or (i % 2 == 1 and k % 2 == 1))
					foreground_white = true;

				else
					foreground_white = false;

				if (j == 0) {

					if (inside)
						cout << char(177) << char(177) << char(177) << char(177) << char(177) << char(177);

					else if (foreground_white) {

						if (printing == piece)
							cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(187);

						else
							cout << char(176) << char(176) << char(176) << char(176) << char(176) << char(176);
					}

					else {

						if (printing == piece)
							cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(187);

						else
							cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178);
					}
				}

				if (j == 1) {

					if (inside)
						cout << char(177);

					else if (printing == piece)
						cout << char(186);

					else if (foreground_white)
						cout << char(176);

					else
						cout << char(178);

					if (printing.color() == WHITE)
						cout << " W";

					if (printing.color() == BLACK)
						cout << " B";

					if (printing.type() == PAWN)
						cout << "P ";

					if (printing.type() == ROOK)
						cout << "R ";

					if (printing.type() == HORSE)
						cout << "H ";

					if (printing.type() == BISHOP)
						cout << "B ";

					if (printing.type() == QUEEN)
						cout << "Q ";

					if (printing.type() == KING)
						cout << "K ";

					if (printing.type() == NONE and printing.color() == NONE) {

						if (inside)
							cout << char(177) << char(177) << char(177) << char(177);

						else if (foreground_white)
							cout << char(176) << char(176) << char(176) << char(176);

						else
							cout << char(178) << char(178) << char(178) << char(178);
					}

					if (inside)
						cout << char(177);

					else if (printing == piece)
						cout << char(186);

					else if (foreground_white)
						cout << char(176);

					else
						cout << char(178);
				}

				if (j == 2) {

					if (inside)
						cout << char(177) << char(177) << char(177) << char(177) << char(177) << char(177);

					else if (foreground_white) {

						if (printing == piece)
							cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(188);

						else
							cout << char(176) << char(176) << char(176) << char(176) << char(176) << char(176);
					}

					else {

						if (printing == piece)
							cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(188);

						else
							cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178);
					}
				}
			}

			cout << endl;
		}
	}

	cout << endl;
	cout << "        A     B     C     D     E     F     G     H " << endl;
}

void Interface::start_game() {

	while (1) {

		int choice = 0;
		string buffer;
		Tile piece;
		vector<Tile> options;

		system("cls");
		draw_board();

		cout << endl;
		cout << endl;

		while (choice == 0 or choice > options.size()) {

			cout << "  Select piece to move: ";
			cin >> buffer;

			piece = select_piece(notation(buffer));

			options.push_back(select_piece(notation("E3")));
			options.push_back(select_piece(notation("E4")));

			cout << options.size() << endl;

			if (select_piece(notation("E3")) == options[0])
				cout << "por favor" << endl;

			draw_moves(piece, options);
		}
	}
}

Tile Interface::select_piece(Position pos) {

	return root_->tile(pos.x(), pos.y());
}

Position Interface::notation(string str) {

	int x;
	int y;

	if (str.size() == 2) {
		if (str[0] >= 'A' and str[0] <= 'H') {

			y = int(str[0]) - 65;

			if (str[1] >= '1' and str[1] <= '8') {

				x = int(str[1]) - 49;

				return Position(x, y);
			}
		}
	}

	throw
		Error("Invalid notation");
}

string Interface::notation(Position pos) {

	string position;

	position += char(pos.y() + 65);
	position += char(pos.x() + 49);

	return position;
}