#include "Board.h"

Board::Board() {

	for (int i = 0; i < 8; i++) {

		vector<Tile> row;

		for (int j = 0; j < 8; j++) {

			row.push_back(Tile());
		}

		board_.push_back(row);
	}

	pawns_.reserve(16);
	rooks_.reserve(4);
	horses_.reserve(4);
	bishops_.reserve(4);
	queens_.reserve(2);
	kings_.reserve(2);

	for (int i : {1, 6}) {

		char color = (i == 1) ? 'W' : 'B';

		for (int j = 0; j < 8; j++) {

			pawns_.push_back(Pawn(color, Position(i, j), this));
			board_[i][j].receive(&pawns_.back());
		}
	}

	for (int i : {0, 7}) {

		char color = (i == 0) ? 'W' : 'B';

		for (int j : {0, 7}) {

			rooks_.push_back(Rook(color, Position(i, j), this));
			board_[i][j].receive(&rooks_.back());
		}

		for (int j : {1, 6}) {

			horses_.push_back(Horse(color, Position(i, j), this));
			board_[i][j].receive(&horses_.back());
		}

		for (int j : {2, 5}) {

			bishops_.push_back(Bishop(color, Position(i, j), this));
			board_[i][j].receive(&bishops_.back());
		}

		queens_.push_back(Queen(color, Position(i, 4), this));
		board_[i][3].receive(&queens_.back());

		kings_.push_back(King(color, Position(i, 4), this));
		board_[i][4].receive(&kings_.back());
	}
}

Tile Board::tile(Position pos) {

	return board_[pos.x()][pos.y()];
}

vector<Tile> Board::operator[](int x) {

	return board_[x];
}