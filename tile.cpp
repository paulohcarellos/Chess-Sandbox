#include "tile.h"

Tile::Tile() {

	piece_ = NULL;
}

Tile::Tile(Piece* piece) {

	piece_ = piece;
}

bool Tile::empty() const {

	return (piece_ == NULL) ? true : false;
}

char Tile::color() const {

	if (empty())
		return ' ';

	return piece_->color();
}

char Tile::type() const {

	if (empty())
		return ' ';

	if (dynamic_cast<Pawn*>(piece_))
		return 'P';

	if (dynamic_cast<Rook*>(piece_))
		return 'R';

	if (dynamic_cast<Horse*>(piece_))
		return 'H';

	if (dynamic_cast<Bishop*>(piece_))
		return 'B';

	if (dynamic_cast<Queen*>(piece_))
		return 'Q';

	if (dynamic_cast<King*>(piece_))
		return 'K';
}

void Tile::clear() {

	piece_ = NULL;
}

void Tile::receive(Piece* in) {

	piece_ = in;
}

vector<Position> Tile::moves() {

	return piece_->moves();
}