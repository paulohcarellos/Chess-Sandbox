#include <iostream>
#include "interface.h"

using namespace std;

int main() {

	ClassicalChess board;
	Interface root(board);

	root.start_game();



	return 0;
}