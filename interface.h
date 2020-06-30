#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "board.h"
#include "history.h"

using namespace std;

class Interface {

	Board* board_;
	History* history_;

public:

	Interface(Board*, History*);
	void clear();
	void drawBoard();
	void drawBoard(Position, vector<Position>);
	void pause();
	void startGame();
};

