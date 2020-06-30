#include "classicalChess.h"

Board ClassicalChessBoard() {

	Board board(8, 8);

	for (int i : {2, 7}) {

		int color = (i == 2) ? WHITE : BLACK;

		for (int j = 1; j <= 8; j++)
			board.addPiece(Position(i, j), color, PAWN);

	}

	for (int i : {1, 8}) {
		
		int color = (i == 1) ? WHITE : BLACK;

		for (int j : {1, 8})
			board.addPiece(Position(i, j), color, ROOK);

		for (int j : {2, 7})
			board.addPiece(Position(i, j), color, HORSE);

		for (int j : {3, 6})
			board.addPiece(Position(i, j), color, BISHOP);

		board.addPiece(Position(i, 4), color, QUEEN);
		board.addPiece(Position(i, 5), color, KING);
	}

	return board;
}

int alternatePlayer(int turn) {

	if (turn == 0)
		return 1;

	return (turn == 1) ? 2 : 1;
}

Position notation(string str) {

	if (str.size() == 2 and str[0] >= 'A' and str[0] <= 'H' and str[1] >= '1' and str[1] <= '8') {

		int x = str[1] - '1' + 1;
		int y = str[0] - 'A' + 1;

		return Position(x, y);
	}
}

string notation(Position pos) {

	string str;

	str += char(pos.y() + 'A' - 1);
	str += char(pos.x() + '1' - 1);

	return str;
}

vector<Position> bishopMoves(Square bishop, Board board) {

	Position it = bishop.position();
	vector<Position> moves;

	while (it.x() < board.height() and it.y() > 1) {

		it = it.up().left();
		Square upLeft = board.square(it);

		if (upLeft.empty())
			moves.push_back(upLeft.position());

		else {

			if (upLeft.color() != bishop.color())
				moves.push_back(upLeft.position());

			break;
		}
	}

	it = bishop.position();

	while (it.x() < board.height() and it.y() < board.width()) {

		it = it.up().right();
		Square upRight = board.square(it);

		if (upRight.empty())
			moves.push_back(upRight.position());

		else {

			if (upRight.color() != bishop.color())
				moves.push_back(upRight.position());

			break;
		}
	}

	it = bishop.position();

	while (it.x() > 1 and it.y() > 1) {

		it = it.down().left();
		Square downLeft = board.square(it);

		if (downLeft.empty())
			moves.push_back(downLeft.position());

		else {

			if (downLeft.color() != bishop.color())
				moves.push_back(downLeft.position());

			break;
		}
	}


	it = bishop.position();

	while (it.x() > 1 and it.y() < board.width()) {

		it = it.down().right();

		Square downRight = board.square(it);

		if (downRight.empty())
			moves.push_back(downRight.position());

		else {

			if (downRight.color() != bishop.color())
				moves.push_back(downRight.position());

			break;
		}
	}

	return moves;
}

vector<Position> checkSuicide(Square piece, vector<Position> moves, Board board) {

	int color = piece.color();
	Position origin = piece.position();
	vector<Position> safeMoves;

	for (Position i : moves) {

		bool suicide = false;
		Board copy = board;

		copy.movePiece(origin, i);

		for (int j = 1, height = board.height(); j <= height and suicide == false; j++) {
			for (int k = 1, width = board.width(); k <= width and suicide == false; k++) {

				Square checking = copy.square(Position(j, k));

				if (!checking.empty() and checking.color() != piece.color()) {

					vector<Position> targets = instantMoves(checking, copy);

					for (Position l : targets) {

						if (copy.square(l).type() == KING) {

							suicide = true;
							break;
						}
					}
				}
			}
		}

		if (!suicide)
			safeMoves.push_back(i);
	}

	return safeMoves;
}

vector<Position> horseMoves(Square horse, Board board) {

	vector<Position> moves;

	for (int i : { -2, -1, 1, 2 }) {
		for (int j : { -2, -1, 1, 2 }) {

			if (abs(i) != abs(j)) {

				int x = horse.position().x() + i;
				int y = horse.position().y() + j;

				if (x >= 1 and x <= board.height() and y >= 1 and y <= board.width()) {

					Square jump = board.square(Position(x, y));

					if (jump.empty() or jump.color() != horse.color())
						moves.push_back(jump.position());
				}
			}
		}
	}

	return moves;
}

vector<Position> instantMoves(Square piece, Board board) {

	if (piece.type() == PAWN)
		return pawnMoves(piece, board);

	if (piece.type() == ROOK)
		return  rookMoves(piece, board);

	if (piece.type() == HORSE)
		return horseMoves(piece, board);

	if (piece.type() == BISHOP)
		return bishopMoves(piece, board);

	if (piece.type() == QUEEN)
		return queenMoves(piece, board);

	if (piece.type() == KING)
		return kingMoves(piece, board);

	return vector<Position>();
}

vector<Position> kingMoves(Square king, Board board) {

	vector<Position> moves;

	for (int i : { -1, 0, 1 }) {
		for (int j : { -1, 0, 1}) {

			int x = king.position().x() + i;
			int y = king.position().y() + j;

			if (x >= 1 and x <= board.height() and y >= 1 and y <= board.width()) {

				Square walk = board.square(Position(x, y));

				if (walk.empty() or walk.color() != king.color())
					moves.push_back(walk.position());
			}
		}
	}

	return moves;
}

vector<Position> pawnMoves(Square pawn, Board board) {

	Position it = pawn.position();
	Position forward;
	vector<Position> moves;

	if (pawn.color() == 1)
		forward = it.up();

	else
		forward = it.down();

	if (forward.x() >= 1 and forward.x() <= 8) {

		Square climb = board.square(forward);

		if (climb.empty())
			moves.push_back(climb.position());

		if (forward.y() > 1) {

			Square attack = board.square(forward.left());

			if (!attack.empty() and attack.color() != pawn.color())
				moves.push_back(attack.position());
		}

		if (forward.y() < 8) {

			Square attack = board.square(forward.right());

			if (!attack.empty() and attack.color() != pawn.color())
				moves.push_back(attack.position());
		}

		if (pawn.fresh()) {

			if (pawn.color() == 1)
				forward = forward.up();

			else
				forward = forward.down();

			Square dash = board.square(forward);

			if (dash.empty())
				moves.push_back(dash.position());
		}
	}

	return moves;
}

vector<Position> queenMoves(Square queen, Board board) {

	vector<Position> moves;

	for (Position i : rookMoves(queen, board))
		moves.push_back(i);

	for (Position i : bishopMoves(queen, board))
		moves.push_back(i);

	return moves;
}

vector<Position> rookMoves(Square rook, Board board) {

	Position it = rook.position();
	vector<Position> moves;

	while (it.x() < board.height()) {

		it = it.up();
		Square up = board.square(it);

		if (up.empty())
			moves.push_back(up.position());

		else {

			if (up.color() != rook.color())
				moves.push_back(up.position());

			break;
		}
	}

	it = rook.position();

	while (it.x() > 1) {

		it = it.down();
		Square down = board.square(it);

		if (down.empty())
			moves.push_back(down.position());

		else {

			if (down.color() != rook.color())
				moves.push_back(down.position());

			break;
		}
	}

	it = rook.position();

	while (it.y() > 1) {

		it = it.left();
		Square left = board.square(it);

		if (left.empty())
			moves.push_back(left.position());

		else {

			if (left.color() != rook.color())
				moves.push_back(left.position());

			break;
		}
	}

	it = rook.position();

	while (it.y() < board.width()) {

		it = it.right();

		Square right = board.square(it);

		if (right.empty())
			moves.push_back(right.position());

		else {

			if (right.color() != rook.color())
				moves.push_back(right.position());

			break;
		}
	}

	return moves;
}

vector<Position> traceMoves(Position place, Board board) {

	Square piece = board.square(place);
	vector<Position> moves = instantMoves(piece, board);

	moves = checkSuicide(piece, moves, board);

	return moves;
}
