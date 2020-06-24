#pragma once
#include <vector>
#include "tile.h"

#define NONE 0
#define PAWN 1
#define ROOK 2
#define HORSE 3
#define BISHOP 4
#define QUEEN 5
#define KING 6

#define WHITE 1
#define BLACK 2

using namespace std;

class ClassicalChess {

	vector<vector<Tile>> board_;
	vector<vector<vector<Tile>>> moves_;

public:

	ClassicalChess();
	Tile tile(int, int);
};
