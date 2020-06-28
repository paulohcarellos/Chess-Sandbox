#pragma once
#include "piece.h"

class Tile {

	Piece* piece_;

public:

	Tile();
	Tile(Piece*);
	bool empty() const;
	char color() const;
	char type() const;
	void clear();
	void receive(Piece*);
	vector<Position> moves();
};

