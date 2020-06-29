#pragma once
#include "position.h"

class Square {

	int color_;
	int type_;
	bool fresh_;
	Position position_;

public:

	Square(int x, int y);
	int x() const;
	int y() const;
	int color() const;
	int type() const;
	void give(int color, int type); //fresh
	void receive(int color, int type); //not fresh
	void clear();
	bool fresh() const;
	bool empty() const;
	Position position() const;
};

