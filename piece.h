#pragma once
#include <vector>
#include "position.h"

class Board;

class Piece {
protected:

	char color_;
	bool fresh_;

	Position position_;
	Board* ref_;

public:

	Piece();
	Piece(char, Position, Board*);
	char color() const;
	void move(Position);
	Position position() const;

	virtual vector<Position> moves() = 0;
};

class Pawn : public Piece {
public:

	Pawn() : Piece() {}
	Pawn(char c, Position p, Board* b) : Piece(c, p, b) {}
	vector<Position> moves();
};

class Rook : public Piece {
public:

	Rook() : Piece() {}
	Rook(char c, Position p, Board* b) : Piece(c, p, b) {}
	vector<Position> moves();
};

class Horse : public Piece {
public:

	Horse() : Piece() {}
	Horse(char c, Position p, Board* b) : Piece(c, p, b) {}
	vector<Position> moves();
};

class Bishop : public Piece {
public:

	Bishop() : Piece() {}
	Bishop(char c, Position p, Board* b) : Piece(c, p, b) {}
	vector<Position> moves();
};

class Queen : public Piece {
public:

	Queen() : Piece() {}
	Queen(char c, Position p, Board* b) : Piece(c, p, b) {}
	vector<Position> moves();
};

class King : public Piece {
public:

	King() : Piece() {}
	King(char c, Position p, Board* b) : Piece(c, p, b) {}
	vector<Position> moves();
};