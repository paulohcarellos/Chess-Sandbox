#include "square.h"

Square::Square(int x, int y) {

	color_ = 0;
	type_ = 0;
	fresh_ = false;
	position_ = Position(x, y);
}

int Square::x() const {

	return position_.x();
}

int Square::y()	 const {

	return position_.y();
}

int Square::color() const {

	return color_;
}

int Square::type() const {

	return type_;
}

void Square::give(int color, int type) {

	color_ = color;
	type_ = type;
	fresh_ = true;
}

void Square::receive(int color, int type) {

	color_ = color;
	type_ = type;
	fresh_ = false;
}

void Square::clear() {

	color_, type_ = 0;
}

bool Square::fresh() const {

	return fresh_;
}

bool Square::empty() const {

	return (color_ == 0) ? true : false;
}

Position Square::position() const {

	return position_;
}