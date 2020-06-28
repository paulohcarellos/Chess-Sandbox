#include "piece.h"
#include "board.h"

Piece::Piece() {

	color_ = 0;
	position_ = Position();
	fresh_ = true;
	ref_ = NULL;
}

Piece::Piece(char color, Position position, Board* board) {

	color_ = color;
	position_ = position;
	fresh_ = true;
	ref_ = board;
}

char Piece::color() const {

	return color_;
}

void Piece::move(Position target) {

	position_ = target;
}

Position Piece::position() const {

	return position_;
}
#include <iostream>
vector<Position> Pawn::moves() {

	vector<Position> targets;

	int x = position_.x();
	int y = position_.y();

	int direction = (color_ == 'W') ? 1 : -1;

	Position foward(x + 1 * direction, y);

	if (ref_->tile(foward).empty())
		targets.push_back(foward);
	
	if (fresh_) {

		Position dash(x + 2 * direction, y);

		if (ref_->tile(dash).empty())
			targets.push_back(dash);
	}

	return targets;
}

vector<Position> Rook::moves() {

	return vector<Position>();
}

vector<Position> Horse::moves() {

	return vector<Position>();
}

vector<Position> Bishop::moves() {

	return vector<Position>();
}

vector<Position> Queen::moves() {

	return vector<Position>();
}

vector<Position> King::moves() {

	return vector<Position>();
}