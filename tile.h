#pragma once
#include "position.h"

class Tile {

	int type_;
	int color_;
	bool fresh_;

	Position self_;
	
public:

	Tile();
	Tile(int, int, Position);
	int type() const;
	int color() const;
	Position position() const;
	bool operator==(const Tile&);

};

/* CODES:

	00 - Empty
	01 - Pawn
	02 - Rook
	03 - Horse
	04 - Bishop
	05 - Queen
	06 - King

	00 - None
	01 - White
	02 - Black

*/
