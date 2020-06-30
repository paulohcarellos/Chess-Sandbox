#pragma once
#include <vector>
#include <string>
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
int alternatePlayer(int);
Position notation(string);
string notation(Position);
vector<Position> bishopMoves(Square, Board);
vector<Position> checkSuicide(Square, vector<Position>, Board);
vector<Position> horseMoves(Square, Board);
vector<Position> instantMoves(Square, Board);
vector<Position> kingMoves(Square, Board);
vector<Position> pawnMoves(Square, Board);
vector<Position> queenMoves(Square, Board);
vector<Position> rookMoves(Square, Board);
vector<Position> traceMoves(Position, Board);
