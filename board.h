#pragma once
#include <iostream>
#include <vector>
#include "tile.h"

using namespace std;

class Board {

	vector<vector<Tile>> board_;

	vector<Pawn> pawns_;
	vector<Rook> rooks_;
	vector<Horse> horses_;
	vector<Bishop> bishops_;
	vector<Queen> queens_;
	vector<King> kings_;
	
public:

	Board();
	Tile tile(Position);
	vector<Tile> operator[](int);
};

