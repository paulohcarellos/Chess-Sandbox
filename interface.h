#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "board.h"

using namespace std;

class Interface {

	Board* board_;

public:

	Interface(Board*);
	void clear();
	void drawBoard();
	void drawBoard(Position, vector<Position>);
	void pause();
	string print(Square) const;
};

