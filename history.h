#pragma once
#include <vector>
#include <string>

using namespace std;

class History {

	vector<string> moves_;

public:

	History() {}
	History(const History& copy) : moves_(copy.moves_) {}
	int size() const { return moves_.size(); }
	string last() const { return moves_.back(); }
	string play(int i) { return moves_[i]; }
	void append(string play) { moves_.push_back(play); }
};