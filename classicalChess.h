#pragma once
#include <vector>
#include "board.h"

using namespace std;

#define PAWN   01
#define ROOK   02
#define HORSE  03
#define BISHOP 04
#define QUEEN  05
#define KING   06

#define WHITE  01
#define BLACK  02

Board ClassicalChessBoard();
vector<Position> traceMoves(Position, Board);
vector<Position> pawnMoves(Position, Board);
vector<Position> rookMoves(Position, Board);
vector<Position> horseMoves(Position, Board);
vector<Position> bishopMoves(Position, Board);
vector<Position> queenMoves(Position, Board);
vector<Position> kingMoves(Position, Board);
