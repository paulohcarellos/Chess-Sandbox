#include "board.h"

Board::Board() {

	height_ = 0;
	width_ = 0;
}
Board::Board(int height, int width) {

	height_ = height;
	width_ = width;

	for (int i = 0; i < height; i++) {

		vector<Square> row;

		for (int j = 0; j < width; j++)
			row.push_back(Square(i + 1, j + 1));

		board_.push_back(row);
	}
}

Board::Board(const Board& copy) {

	height_ = copy.height_;
	width_ = copy.width_;
	board_ = copy.board_;
}

int Board::height() const {

	return height_;
}

int Board::width() const {

	return width_;
}

void Board::addPiece(Position place, int color, int type) {

	square(place).give(color, type);
}

void Board::movePiece(Position piece, Position target) {

	square(target).receive(square(piece).color(), square(piece).type());
	square(piece).clear();
}

void Board::removePiece(Position piece) {

	square(piece).clear();
}

Square& Board::square(Position place) {

	return board_[place.x() - 1][place.y() - 1];
}