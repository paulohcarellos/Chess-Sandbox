#include <iostream>
#include "board.h"
#include "classicalChess.h"
#include "interface.h"
#include "history.h"

using namespace std;

int main() {

	Board board = ClassicalChessBoard();
	History plays;
	Interface root(&board, &plays);

	root.startGame();

	return 0;
}