#pragma once

class Position {

	int x_;
	int y_;

public:

	Position() : x_(0), y_(0) {}
	Position(int x, int y) : x_(x), y_(y) {}
	Position(const Position& copy) : x_(copy.x_), y_(copy.y_) {}
	int x() const { return x_; }
	int y() const { return y_; }
	bool operator==(const Position& p) { return (x_ == p.x_ and y_ == p.y_) ? true : false; }
	Position up() const { return Position(x_ + 1, y_); }
	Position down() const { return Position(x_ - 1, y_); }
	Position left() const { return Position(x_, y_ - 1); }
	Position right() const { return Position(x_, y_ + 1); }
};