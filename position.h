#pragma once

class Position {

	int x_;
	int y_;

public:

	Position() : x_(0), y_(0) {}
	Position(int px, int py) : x_(px), y_(py) {}
	int x() const { return x_; }
	int y() const { return y_; }
};