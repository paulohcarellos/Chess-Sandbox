#pragma once
#include <vector>
#include "square.h"

using namespace std;

class Board {

	int height_;
	int width_;
	vector<vector<Square>> board_;

public:

	Board();
	Board(int height, int width);
	Board(const Board&);
	int height() const;
	int width() const;
	void addPiece(Position, int color, int type);
	void movePiece(Position piece, Position target);
	void removePiece(Position);
	Square& square(Position);
	vector<Position> moves() const;
};

