#pragma once
#include <string>

using namespace std;

class Position {

	int x_;
	int y_;

public:

	Position();
	Position(int, int);
	Position(const Position& copy);
	Position(string);
	int x() const;
	int y() const;
	bool valid() const;
	bool operator==(const Position& p) const;
};