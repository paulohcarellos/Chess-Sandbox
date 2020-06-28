#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "board.h"

class Interface {

	Board board_;

public:

	Interface() {};
	void clear();
	void drawBoard();
	void drawBoard(Position, vector<Position>);
	void move(Position, Position);
	void pause();
	void select(Position);
	void start();
};

