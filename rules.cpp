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

vector<Position> traceMoves(Position place, Board board) {

	Square piece = board.square(place);

	if (piece.type() == PAWN)
		return pawnMoves(place, board);

	if (piece.type() == ROOK)
		return rookMoves(place, board);

	if (piece.type() == HORSE)
		return horseMoves(place, board);

	if (piece.type() == BISHOP)
		return bishopMoves(place, board);

	if (piece.type() == QUEEN)
		return queenMoves(place, board);

	if (piece.type() == KING)
		return kingMoves(place, board);

	return vector<Position>();
}

vector<Position> pawnMoves(Position place, Board board) {

	Square pawn = board.square(place);
	Position it = pawn.position();
	vector<Position> moves;

	if (pawn.color() == 1) {

		if (it.x() < board.height()) {

			Square up = board.square(it.up());

			if (up.empty())
				moves.push_back(up.position());
		}

		if (it.y() > 1) {

			Square attack = board.square(it.up().left());

			if (!attack.empty() and attack.color() != pawn.color())
				moves.push_back(attack.position());
		}

		if (it.y() < board.width()) {

			Square attack = board.square(it.up().right());

			if (!attack.empty() and attack.color() != pawn.color())
				moves.push_back(attack.position());
		}

		if (pawn.fresh()) {

			Square dash = board.square(it.up().up());

			if (dash.empty())
				moves.push_back(dash.position());
		}
	}

	return moves;
}

vector<Position> rookMoves(Position place, Board board) {

	Square rook = board.square(place);
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

vector<Position> horseMoves(Position place, Board board) {

	Square horse = board.square(place);
	vector<Position> moves;

	for (int i : { -2, -1, 1, 2 }) {
		for (int j : { -2, -1, 1, 2 }) {

			if (abs(i) != abs(j)) {

				int x = place.x() + i;
				int y = place.y() + j;

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

vector<Position> bishopMoves(Position place, Board board) {

	Square bishop = board.square(place);
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

vector<Position> queenMoves(Position place, Board board) {

	vector<Position> moves;

	for (Position i : rookMoves(place, board))
		moves.push_back(i);

	for (Position i : bishopMoves(place, board))
		moves.push_back(i);

	return moves;
}

vector<Position> kingMoves(Position place, Board board) {

	Square king = board.square(place);
	vector<Position> moves;

	for (int i : { -1, 0, 1 }) {
		for (int j : { -1, 0, 1} ) {

			int x = place.x() + i;
			int y = place.y() + j;

			if (x >= 1 and x <= board.height() and y >= 1 and y <= board.width()) {

				Square walk = board.square(Position(x, y));

				if (walk.empty() or walk.color() != king.color())
					moves.push_back(walk.position());
			}
		}
	}

	return moves;
}