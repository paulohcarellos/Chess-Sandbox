#include "tile.h"

Tile::Tile() {

	type_ = 0;
	color_ = 0;
	fresh_ = false;
	self_ = Position();
}

Tile::Tile(int type, int color, Position self) {

	type_ = type;
	color_ = color;
	self_ = self;

	if (type != 0)
		fresh_ = true;

	else
		fresh_ = false;
}

int Tile::type() const {

	return type_;
}

int Tile::color() const {

	return color_;
}

bool Tile::operator==(const Tile& check) {

	if (type_ == check.type_) {
		if (color_ == check.color_) {
			if (!(fresh_ xor check.fresh_)) {
				if (self_.x() == check.self_.x()) {
					if (self_.y() == check.self_.y())
						return true;
				}
			}
		}
	}

	return false;
}
