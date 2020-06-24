#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "error.h"
#include "boards.h"

using namespace std;

class Interface {

	ClassicalChess* root_;

public:

	Interface(ClassicalChess&);
	void draw_board();
	void draw_moves(Tile, vector<Tile>);
	void start_game();
	Tile select_piece(Position);
	Position notation(string);
	string notation(Position);
};

