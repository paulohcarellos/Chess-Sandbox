#include <iostream>
#include "board.h"
#include "classicalChess.h"
#include "interface.h"

using namespace std;

int main() {

	Board board = ClassicalChessBoard();
	Interface root(&board);

	root.startGame();

	return 0;
}