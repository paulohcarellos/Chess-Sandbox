#include "boards.h"

ClassicalChess::ClassicalChess() {

	for (int i = 0; i < 8; i++) {

		int color;
		int it;
		vector<Tile> adding;

		if (i == 0 or i == 1)
			color = WHITE;

		if (i == 6 or i == 7)
			color = BLACK;;

		if (i == 0 or i == 7) {

			it = 0;
			adding.push_back(Tile(ROOK, color, Position(i, it++)));
			adding.push_back(Tile(HORSE, color, Position(i, it++)));
			adding.push_back(Tile(BISHOP, color, Position(i, it++)));
			adding.push_back(Tile(QUEEN, color, Position(i, it++)));
			adding.push_back(Tile(KING, color, Position(i, it++)));
			adding.push_back(Tile(BISHOP, color, Position(i, it++)));
			adding.push_back(Tile(HORSE, color, Position(i, it++)));
			adding.push_back(Tile(ROOK, color, Position(i, it++)));
		}

		else if (i == 1 or i == 6) {

			for (int j = 0; j < 8; j++)
				adding.push_back(Tile(PAWN, color, Position(i, j)));
		}

		else
			for (int j = 0; j < 8; j++)
				adding.push_back(Tile(NONE, NONE, Position(i, j)));

		board_.push_back(adding);
	}
}

Tile ClassicalChess::tile(int x, int y) {

	return board_[x][y];
}
