#include <iostream>
#include "board.h"
#include "classicalChess.h"
#include "interface.h"

using namespace std;

int main() {

	Board board(8, 8);
	Interface root(&board);

	Position selected(2, 2);
	board.addPiece(selected, 1, 6);
	board.addPiece(Position(3, 3), 2, 2);
	board.addPiece(Position(2, 3), 1, 2);
	root.drawBoard();
	root.pause();
	
	vector<Position> moves = traceMoves(selected, board);

	root.drawBoard(selected, moves);

	return 0;
}