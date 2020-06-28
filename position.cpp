#include "position.h"

Position::Position() {

	x_ = -1;
	y_ = -1;
}

Position::Position(int x, int y) {

	x_ = x;
	y_ = y;
}

Position::Position(const Position& copy) {
	
	x_ = copy.x_;
	y_ = copy.y_;
}

Position::Position(string notation) : Position() {

	if (notation.size() == 2) {
		if (notation[0] >= 'A' and notation[0] <= 'H') {
			if (notation[1] >= '1' and notation[1] <= '8') {

				x_ = notation[1] - '1';
				y_ = notation[0] - 'A';
			}
		}
	}
}

int Position::x() const{
	
	return x_;
}

int Position::y() const{

	return y_;
}

bool Position::valid() const {

	if (x_ >= 0 and x_ < 7 and y_ >= 0 and y_ <= 7)
		return true;

	return false;
}

bool Position::operator==(const Position& comp) const {

	return (x_ == comp.x_ and y_ == comp.y_) ? true : false;
}